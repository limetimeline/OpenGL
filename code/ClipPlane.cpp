#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

void MyDisplay() {
	GLdouble eqn1[4] = { 0.0, 1.0, 0.0, 0.0 };
	GLdouble eqn2[4] = { 1.0, 0.0, 0.0, 0.0 };
	GLdouble eqn3[4] = { 1.0, 1.0, 0.0, 0.0 };
	GLdouble eqn4[4] = { 1.0, 0.0, 0.0, 0.5 };
	GLdouble eqn[4] = { 0.0, -1.0, 0.0, 0.0 };

	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);

	glTranslatef(0.0, 0.0, -5.0);
	
	// 1번
	//glClipPlane(GL_CLIP_PLANE0, eqn1);
	//glEnable(GL_CLIP_PLANE0);

	// 2번
	glClipPlane(GL_CLIP_PLANE0, eqn1);
	glEnable(GL_CLIP_PLANE0);

	//glClipPlane(GL_CLIP_PLANE1, eqn2);
	//glEnable(GL_CLIP_PLANE1);

	//glClipPlane(GL_CLIP_PLANE0, eqn);
	//glEnable(GL_CLIP_PLANE0);

	glRotatef(90.0, 1.0, 0.0, 0.0);

	glutWireSphere(1.0, 20, 16);
	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 10.0);
}


int main() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(500, 400);
	glutCreateWindow("Clip Plane");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}
