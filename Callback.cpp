#include <GL/glut.h>
#include <stdio.h>

double r_val = 0.5;
double g_val = 0.5;
double b_val = 0.5;

int x_pos = 0;
int y_pos = 0;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r_val, g_val, b_val);
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed) {
		case 'q':
			exit(0); break;
		case 'R':
			r_val = 1;
			break;
		case 'G':
			g_val = 1;
			break;
		case 'B':
			b_val = 1;
			break;
		case 'r':
			b_val += 0.1;
			break;
		case 'g':
			b_val += 0.1;
			break;
		case 'b':
			b_val += 0.1;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void MySpecialKeyboard(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_UP:
			y_pos = y_pos - 1;
			break;
		case GLUT_KEY_DOWN:
			y_pos = y_pos + 1;
			break;
		case GLUT_KEY_LEFT:
			x_pos = x_pos - 1;
			break;
		case GLUT_KEY_RIGHT:
			x_pos = x_pos + 1;
			break;
		default:
			break;
	}
	glutPositionWindow(x_pos, y_pos);
	glutPostRedisplay();
}

int main() {
	glutInitWindowSize(300, 300);
	glutCreateWindow("김상현");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecialKeyboard);
	glutMainLoop();
	return 0;
}
