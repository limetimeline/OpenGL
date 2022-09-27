#include <GL/glut.h>
#include <stdio.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glRotatef(45, 1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glutWireCube(0.5);

	glRotatef(10, 1.0, 1.0, 1.0);
	glViewport(300, 300, 300, 300);
	glColor3f(1.0, 1.0, 0.0);
	glutWireCone(0.5, 1, 10, 10);

	glRotatef(-10, 1.0, 1.0, 1.0);
	glViewport(0, 300, 300, 300);
	glColor3f(1.0, 0.0, 0.0);
	glutWireSphere(0.5, 20, 10);

	glRotatef(-5, 1.0, 1.0, 1.0);
	glViewport(300, 0, 300, 300);
	glColor3f(0.0, 1.0, 0.0);
	glutWireTorus(0.2, 0.5, 20, 20);




	glFlush();
}

int main() {
	glutInitWindowSize(600, 600);
	glutCreateWindow("김상현");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
