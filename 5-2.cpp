#include <GL/glut.h>
#include <stdio.h>

void MyDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(20.0);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POINTS);
		glVertex3f(0.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.5, 0.5, 0.0);
	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);
		glColor3f(0, 1.0, 0);
		glVertex3f(-0.8, 0.8, 0);
		glVertex3f(0.8, -0.8, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0.8, 0, 0);
	glEnd();

	glPolygonMode(GL_FRONT, GL_FILL);
	glBegin(GL_POLYGON);
		glColor3f(0, 0, 1.0);
		glVertex3f(-0.8, -0.8, 0);
		glVertex3f(-0.4, 0.0, 0);
		glVertex3f(0.0, -0.8, 0);
	glEnd();

	glPolygonMode(GL_FRONT, GL_LINE);
	glBegin(GL_POLYGON);
		glColor3f(0, 1.0, 1.0);
		glVertex3f(0, 0.8, 0);
		glVertex3f(-0.3, 0.3, 0);
		glVertex3f(0.3, 0.3, 0);
	glEnd();





	glFlush();
}

int main() {
	glutInitWindowSize(500, 500);
	glutCreateWindow("김상현");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
