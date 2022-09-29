#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>



void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0,0,0);
	glutSolidTeapot(0.1);

	glPushMatrix();
		glTranslatef(0.1, 0.1, 0.0);
		glutSolidTeapot(0.1);
		glPushMatrix();
			glTranslatef(0.5, 0.1, 0.0);
			glRotatef(45, 0.0, 0.0, 1.0);
			glutSolidTeapot(0.05);
		glPopMatrix();
			glTranslated(-0.25, 0.1, 0.0);
			glRotatef(90, 0.0, 1.0, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glutSolidTeapot(0.2);
	glPopMatrix();
		glTranslatef(0.0, 0.5, 0.0);
		glColor3f(0, 0, 1);
		glutSolidTeapot(0.2);


	glFlush();
}





int main() {
	glutInitWindowSize(300, 300);
	glutCreateWindow("김상현");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);


	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
