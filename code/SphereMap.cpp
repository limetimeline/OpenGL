#define _CRT_SECURE_NO_WARNINGS
#include <GL/glut.h>
#include <GL/glaux.h>
#include <stdio.h>

GLfloat xrot = 0.9f, yrot = 0.8f, zrot = 1.0f;
AUX_RGBImageRec* pTextureImage[1];

void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		glLoadIdentity();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
		glEnd();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);

	glMatrixMode(GL_MODELVIEW);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);

	// glutSolidCube(1.0); // glutSolidTorus(0.5, 1.0, 50, 50);
	glutSolidTeapot(1.0);
	glutSwapBuffers();
}

void MyTimer(int Value) {
	glutPostRedisplay();
	glutTimerFunc(50, MyTimer, 1);
}

AUX_RGBImageRec* LoadBMP(const char* szFilename) {
	FILE* pFile = NULL;
	if (!szFilename)
		return NULL;
	pFile = fopen(szFilename, "r");
	if (pFile) {
		fclose(pFile);
		return auxDIBImageLoad(szFilename);
	}
	return NULL;
}

int LoadGLTextures(const char* szFilePath) {
	int Status = FALSE;
	glClearColor(0.0, 0.0, 0.0, 0.5);
	memset(pTextureImage, 0, sizeof(void*) * 1);

	if (pTextureImage[0] = LoadBMP(szFilePath))
	{
		Status = TRUE;
		glTexImage2D(GL_TEXTURE_2D, 0, 3,
			pTextureImage[0]->sizeX, pTextureImage[0]->sizeY,
			0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[0]->data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	return Status;
}

int main(int argc, char** argv) {
	if (argc <= 1)
	{
		printf("\n%s\n\n", "Usage : TextureCube [BMPFileName.bmp]"); exit(1);
	}
	else if (argc > 2)
	{
		printf("\nToo Many Arguments!\nArgument is Only one\n"); exit(1);
	}
	else {
		printf("OK..\n");
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(700, 700);
		glutCreateWindow("김상현");
		glutDisplayFunc(MyDisplay);
		glutReshapeFunc(MyReshape);
		glutTimerFunc(500, MyTimer, 1);
		if (LoadGLTextures(argv[1]))
		{
			glEnable(GL_TEXTURE_2D);
			glShadeModel(GL_SMOOTH);
			glClearDepth(1.0);
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LEQUAL);
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
			glutMainLoop();
		}
	}
	return 0;
}
