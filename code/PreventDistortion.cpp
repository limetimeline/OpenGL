#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <stdio.h>

int Width, Height;

void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
}


void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(2.0, 0.0, 2.0);
		glVertex3f(2.0, 0.0, -2.0);
		glVertex3f(-2.0, 0.0, -2.0);
		glVertex3f(-2.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();
	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
		glTranslatef(0.0, 0.0, -0.5);
		glutWireTeapot(1.0);
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	// 순서 : glMatrixMode(GL_PROJECTION) -> glLoadIdentity() -> gluPerspective() -> glMatrixMode(GL_MODELVIEW)
	// 물체, 카메라 위치 및 방향에 대한 기하 변환 -> glMatrixMode(GL_PROJECTION)

	/* glViewport(left, bottom, width, height) */
	glViewport(0, 0, Width / 2, Height / 2); // 3사분면
	glMatrixMode(GL_PROJECTION); // 촬영 방법 및 렌즈 선택에 대한 기하 변환
	glPushMatrix();
		glLoadIdentity();
		/* gluPerspective(fov, aspect, near, far) */
		gluPerspective(30, (GLdouble)Width / (GLdouble)Height, 1.0, 50.0); // 종횡비를 뷰포트와 일치. (왜곡 방지)
		glMatrixMode(GL_MODELVIEW); // 물체, 카메라 위치 및 방향에 대한 기하 변환
		glPushMatrix();
			gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			DrawScene();
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glViewport(Width / 2, 0, Width / 2, Height / 2); // 4사분면
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluPerspective(30, (GLdouble)Width / (GLdouble)Height, 1.0, 50.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		gluLookAt(5.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			DrawScene();
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glViewport(0, Height / 2, Width / 2, Height / 2); // 2사분면
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluPerspective(40, (GLdouble)Width / (GLdouble)Height, 1.0, 50.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			gluLookAt(0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
			DrawScene();
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);// 1사분면
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		//gluPerspective(30, 1.0, 3.0, 50.0);
		gluPerspective(30, (GLdouble)Width / (GLdouble)Height, 1.0, 50.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			DrawScene();
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glFlush();
}

void MyReshape(int w, int h) {
	Width = w;
	Height = h;
}

int main(int argc, char** argv) {
	Width = 500; Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("김상현");
	Init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}
