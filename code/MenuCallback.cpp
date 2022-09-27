#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

bool IsSphere = true;
bool IsTorus;
bool IsTeapot;

float scale = 0.1f;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	if (IsSphere)
	{
		glutWireSphere(scale, 15, 15);
	}
	else if (IsTorus) {
		glutWireTorus(scale, 0.3, 40, 20);
	}
	else if (IsTeapot) {
		glutWireTeapot(scale);
	}
	glFlush();
}


void MyMainMenu1(int entryID) {
	if (entryID == 1)
	{
		IsSphere = true;
		IsTorus = false;
		IsTeapot = false;
	}
	else if (entryID == 2) {
		IsTorus = true;
		IsSphere = false;
		IsTeapot = false;
	}
	else {
		IsTorus = false;
		IsSphere = false;
		IsTeapot = true;
	}
	glutPostRedisplay();
}

void MyMainMenu2(int entryID) {
	if (entryID == 1)
	{
		glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
	}
	else if (entryID == 2) {
		glTranslatef(0.2f, 0.0f, 0.0f);
	}
	else {
		scale *= 2;
	}
	glutPostRedisplay();
}


int main() {
	glutInitWindowSize(300, 300);
	glutCreateWindow("김상현");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint MyMainMenuID1 = glutCreateMenu(MyMainMenu1);
	glutSetMenu(MyMainMenuID1);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);
	glutAddMenuEntry("Draw Teapot", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	GLint MyMainMenuID2 = glutCreateMenu(MyMainMenu2);
	glutSetMenu(MyMainMenuID2);
	glutAddMenuEntry("Translate", 1);
	glutAddMenuEntry("Rotate", 2);
	glutAddMenuEntry("Scale", 3);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
