#include <GL/glut.h>

bool bLight0, bLight1;

GLfloat Ia = 0.5, Id = 0.5, Is = 0.5;
GLfloat Ka = 0.5, Kd = 0.5, Ks = 0.5;
GLfloat ConstantAtt = 0.5, LinearAtt = 0.5, QuadraticAtt = 0.5;

void MyLightInit() {
	// 0번광원
	GLfloat light0_ambient[] = { Ia, 0.0, 0.0, 1.0 }; // la : 주변광 특성
	GLfloat light0_diffuse[] = { Id, 0.0, 0.0, 1.0 }; // ld : 확산광 특성
	GLfloat light0_specular[] = { Is, 1.0, 1.0, 1.0 }; // ls : 경면광 특성

	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); // la 설정
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // ld 설정
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); // ls 설정

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0); // 거리 감쇠(상수)
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0); // 거리 감쇠(상수)
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0); // 거리 감쇠(상수)

	// 1번광원
	GLfloat light1_ambient[] = { 0.0, 1.0, 0.0, 1.0 }; // la : 주변광 특성
	GLfloat light1_diffuse[] = { 0.0, 1.0, 0.0, 1.0 }; // ld : 확산광 특성
	GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // ls : 경면광 특성

	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient); // la 설정
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse); // ld 설정
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular); // ls 설정

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0); // 거리 감쇠(상수)
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 1.0); // 거리 감쇠(상수)
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 1.0); // 거리 감쇠(상수)
}

// 물체의 특성
void MyMaterialInit() {
	GLfloat material_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // Ka : 주변광 계수
	GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // Kd : 확산광 계수
	GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Ks : 경면광 계수
	GLfloat material_shiniess[] = { 25 }; // n : 광택 계수

	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient); // Ka 설정
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse); // Kd 설정
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular); // Ks 설정
	glMaterialfv(GL_FRONT, GL_SHININESS, material_shiniess); // n 설정
}

void MyReshape(int w, int h) {
	if (w < h)
		glViewport(0, 0, (GLsizei)w, (GLsizei)w);
	else
		glViewport(0, 0, (GLsizei)h, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); // 투싱행렬
	glLoadIdentity(); // 항등행렬 로드
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 평행투상
}

void DoMenu(int value) {
	switch (value) {
	case 1:
		bLight0 = GL_TRUE;
		break;
	case 2:
		bLight0 = GL_FALSE;
		break;
	case 3:
		bLight1 = GL_TRUE;
		break;
	case 4:
		bLight1 = GL_FALSE;
		break;
	}
	glutPostRedisplay();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();

	// 조명 기능 활성화
	glEnable(GL_LIGHTING);

	if (bLight0)
	{
		// 0번 광원 배치
		glEnable(GL_LIGHT0);
		GLfloat light0_position[] = { -2.0, -2.0, 2.0, 2.0 }; // 광원의 위치 (맨 끝이 0이 아니면 위치성광원)
		glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	}
	else {
		glDisable(GL_LIGHT0);
	}

	if (bLight1)
	{
		// 1번 광원 배치
		glEnable(GL_LIGHT1);
		GLfloat light1_position[] = { 3.0, 3.0, 3.0, 3.0 }; // 광원의 위치
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

		// 1번 광원 Spotlight
		GLfloat spot_direction[] = { -1.0, -1.0, -1.0 }; // 원점으로부터의 광원벡터 방향
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 15.0); // 조명각 0-90도 (p. 545)
		glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 12.0); // 조명승수 (광택계수와 유사)
	}
	else {
		glDisable(GL_LIGHT1);
	}




	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();
	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int x, int y) {
	switch (key) {
	case 'q':
		Ia += 0.1;
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
	glutPostRedisplay();
}

int main() {
	glutCreateWindow("OpenGL");
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	MyLightInit(); // 광원의 특성
	MyMaterialInit(); // 물체의 특성

	GLint DoMenuID1 = glutCreateMenu(DoMenu);
	glutSetMenu(DoMenuID1);
	glutAddMenuEntry("bLight0 On", 1);
	glutAddMenuEntry("bLight0 Off", 2);
	glutAddMenuEntry("bLight1 On", 3);
	glutAddMenuEntry("bLight1 Off", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(DoDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}
