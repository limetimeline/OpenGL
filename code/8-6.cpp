#include <GL/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
		glVertex3f(-0.9, -0.9, 0.1); // DepthMask false이면 기본 1.0에 그려지는 순서대로 나옴
		glVertex3f(0.9, -0.9, 0.1);
		glVertex3f(0.9, 0.9, 0.1);
		glVertex3f(-0.9, 0.9, 0.1);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(0.0, 0.5, 0.5);
	glEnd();
	glDepthMask(GL_TRUE);
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f(-0.9, -0.9, 0.1);
		glVertex3f(0.9, -0.9, 0.1);
		glVertex3f(0.9, 0.9, 0.1);
		glVertex3f(-0.9, 0.9, 0.1);
	glEnd();
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.5, 0.5, 0.05);
		glVertex3f(-0.5, 0.5, 0.05);
		glVertex3f(0.0, -0.5, 0.05);
	glEnd();
	glFlush();
}

int main() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(500, 400);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
