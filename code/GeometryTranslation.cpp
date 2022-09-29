#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>



void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glPolygonMode(GL_FRONT, GL_FILL);

	//glScalef(0.5, 1.0, 1.0);
	// 
	//glRotatef(45, 0.0, 0.0, 1.0);

	//glTranslatef(0.5, 0.0, 0.0);
	//glRotatef(45, 0.0, 0.0, 1.0);

	//glRotatef(45, 0.0, 0.0, 1.0);
	//glTranslatef(0.5, 0.0, 0.0);

	//glBegin(GL_POLYGON);
	//	glColor3f(1.0, 0, 0.0);
	//	glVertex3f(0.0, 0.5, 0);
	//	glColor3f(0.0, 1.0, 0.0);
	//	glVertex3f(-0.5, -0.5, 0);
	//	glColor3f(0.0, 0, 1.0);
	//	glVertex3f(0.5, -0.5, 0);
	//glEnd();

	//glRotatef(90, 1.0, 0.0, 0.0);
	//glColor3f(1.0, 1.0, 0.0);
	//glutWireSphere(0.5, 10, 20);

	glLoadIdentity();
	glScalef(0.5, 1.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);
	

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0, 0.0);
		glVertex3f(0.0, 0.5, 0);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-0.5, -0.5, 0);
		glColor3f(0.0, 0, 1.0);
		glVertex3f(0.5, -0.5, 0);
	glEnd();

	glLoadIdentity();



	glTranslatef(0.75, 0.75, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.25, 0.25, 0.25);

	
	glColor3f(1.0, 1.0, 0.0);
	glutWireSphere(0.5, 10, 20);

	glFlush();
}





int main() {
	glutInitWindowSize(300, 300);
	glutCreateWindow("김상현");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);


	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
