#include <GL/glut.h>

void MyDisplay() {
	glColor3f(0.0, 0.0, 1.0);
	glViewport(150, 150, 150, 150);
	glutWireTeapot(0.5);


	glViewport(0, 0, 150, 150);
	glColor3f(1.0, 0.0, 0.0);
	glutWireTorus(0.3, 0.6, 10, 20);
	glFlush();
}

int main() {
	glutInitWindowSize(300, 300);
	glutCreateWindow("김상현");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
