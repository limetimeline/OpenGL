#include <GL/glut.h>

bool bLight0, bLight1;

GLfloat Ia = 0.5, Id = 0.5, Is = 0.5;
GLfloat Ka = 0.5, Kd = 0.5, Ks = 0.5;
GLfloat ConstantAtt = 0.5, LinearAtt = 0.5, QuadraticAtt = 0.5;
GLfloat PosX0 = -2.0, PosY0 = -2.0, PosZ0 = 2.0;
GLfloat PosX1 = 3.0, PosY1 = 3.0, PosZ1 = -3.0;
int rgb1=1, rgb2=2;

void MyLightInit() {
	// 0번광원
	GLfloat light0_ambient[] = { Ia, 0.0, 0.0, 1.0 }; // la : 주변광 특성
	GLfloat light0_diffuse[] = { Id, 0.0, 0.0, 1.0 }; // ld : 확산광 특성
	if (rgb1 == 1)
	{
		light0_ambient[0] = Ia;
		light0_ambient[1] = 0.0;
		light0_ambient[2] = 0.0;

		light0_diffuse[0] = Id;
		light0_diffuse[1] = 0.0;
		light0_diffuse[2] = 0.0;
	}
	else if (rgb1 == 2)
	{
		light0_ambient[0] = 0.0;
		light0_ambient[1] = Ia;
		light0_ambient[2] = 0.0;

		light0_diffuse[0] = 0.0;
		light0_diffuse[1] = Id;
		light0_diffuse[2] = 0.0;
	}
	else if(rgb1 == 3)
	{
		light0_ambient[0] = 0.0;
		light0_ambient[1] = 0.0;
		light0_ambient[2] = Ia;

		light0_diffuse[0] = 0.0;
		light0_diffuse[1] = 0.0;
		light0_diffuse[2] = Id;
	}

	GLfloat light0_specular[] = { Is, Is, Is, Is }; // ls : 경면광 특성

	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); // la 설정
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // ld 설정
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); // ls 설정

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, ConstantAtt); // 거리 감쇠(상수)
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, LinearAtt); // 거리 감쇠(상수)
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, QuadraticAtt); // 거리 감쇠(상수)

	// 1번광원
	GLfloat light1_ambient[] = { 0.0, Ia, 0.0, 1.0 }; // la : 주변광 특성
	GLfloat light1_diffuse[] = { 0.0, Id, 0.0, 1.0 }; // ld : 확산광 특성

	if (rgb2 == 1)
	{
		light1_ambient[0] = Ia;
		light1_ambient[1] = 0.0;
		light1_ambient[2] = 0.0;

		light1_diffuse[0] = Id;
		light1_diffuse[1] = 0.0;
		light1_diffuse[2] = 0.0;
	}
	else if (rgb2 == 2)
	{
		light1_ambient[0] = 0.0;
		light1_ambient[1] = Ia;
		light1_ambient[2] = 0.0;

		light1_diffuse[0] = 0.0;
		light1_diffuse[1] = Id;
		light1_diffuse[2] = 0.0;
	}
	else if(rgb2 == 3)
	{
		light1_ambient[0] = 0.0;
		light1_ambient[1] = 0.0;
		light1_ambient[2] = Ia;

		light1_diffuse[0] = 0.0;
		light1_diffuse[1] = 0.0;
		light1_diffuse[2] = Id;
	}

	GLfloat light1_specular[] = { Is, Is, Is, Is }; // ls : 경면광 특성

	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient); // la 설정
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse); // ld 설정
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular); // ls 설정

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, ConstantAtt); // 거리 감쇠(상수)
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, LinearAtt); // 거리 감쇠(상수)
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, QuadraticAtt); // 거리 감쇠(상수)
}

// 물체의 특성
void MyMaterialInit() {
	GLfloat material_ambient[] = { Ka, Ka, Ka, 1.0 }; // Ka : 주변광 계수
	GLfloat material_diffuse[] = { Kd, Kd, Kd, 1.0 }; // Kd : 확산광 계수
	GLfloat material_specular[] = { Ks, Ks, Ks, 1.0 }; // Ks : 경면광 계수
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
	glMatrixMode(GL_PROJECTION); // 투상행렬
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

void DoMenuLight0(int value) {
	switch (value) {
	case 1:
		PosX0 += 1.0;
		break;
	case 2:
		PosX0 -= 1.0;
		break;
	case 3:
		PosY0 += 1.0;
		break;
	case 4:
		PosY0 -= 1.0;
		break;
	case 5:
		PosZ0 += 1.0;
		break;
	case 6:
		PosZ0 -= 1.0;
		break;
	}
	glutPostRedisplay();
}

void DoMenuLight1(int value) {
	switch (value) {
	case 1:
		PosX1 += 1.0;
		break;
	case 2:
		PosX1 -= 1.0;
		break;
	case 3:
		PosY1 += 1.0;
		break;
	case 4:
		PosY1 -= 1.0;
		break;
	case 5:
		PosZ1 += 1.0;
		break;
	case 6:
		PosZ1 -= 1.0;
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
		GLfloat light0_position[] = { PosX0, PosY0, PosZ0, 2.0 }; // 광원의 위치 (맨 끝이 0이 아니면 위치성 광원, 0이면 방향성 광원)
		glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	}
	else {
		glDisable(GL_LIGHT0);
	}

	if (bLight1)
	{
		// 1번 광원 배치
		glEnable(GL_LIGHT1);
		GLfloat light1_position[] = { PosX1, PosY1, PosZ1, 3.0 }; // 광원의 위치
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

		//// 1번 광원 Spotlight
		//GLfloat spot_direction[] = { -1.0, -1.0, -1.0 }; // 원점으로부터의 광원벡터 방향
		//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
		//glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 15.0); // 조명각 0-90도 (p. 545)
		//glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 12.0); // 조명승수 (광택계수와 유사)
	}
	else {
		glDisable(GL_LIGHT1);
	}




	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();
	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int x, int y) {
	switch (KeyPressed) {
	case 'q':
		Ia += 0.1;
		break;
	case 'w':
		Ia -= 0.1;
		break;
	case 'e':
		Id += 0.1;
		break;
	case 'r':
		Id -= 0.1;
		break;
	case 'a':
		Is += 0.1;
		break;
	case 's':
		Is -= 0.1;
		break;
	case 'd':
		Ka += 0.1;
		break;
	case 'f':
		Ka -= 0.1;
		break;
	case 'z':
		Kd += 0.1;
		break;
	case 'x':
		Kd -= 0.1;
		break;
	case 'c':
		Ks += 0.1;
		break;
	case 'v':
		Ks -= 0.1;
		break;
	case 't':
		ConstantAtt += 0.1;
		break;
	case 'y':
		ConstantAtt -= 0.1;
		break;
	case 'g':
		LinearAtt += 0.1;
		break;
	case 'h':
		LinearAtt -= 0.1;
		break;
	case 'b':
		QuadraticAtt += 0.1;
		break;
	case 'n':
		QuadraticAtt -= 0.1;
		break;
	case 'u':
		rgb1 = rand()% 3 + 1;
		break;
	case 'i':
		rgb2 = rand() % 3 + 1;
	//case 'i':
	//	Pos -= 0.1;
	//	break;
	default:
		break;
	}
	glutPostRedisplay();
	MyLightInit();
}

int main() {
	glutCreateWindow("김상현");
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

	GLint DoMenuID2 = glutCreateMenu(DoMenuLight0);
	glutSetMenu(DoMenuID2);
	glutAddMenuEntry("light0 +x", 1);
	glutAddMenuEntry("light0 -x", 2);
	glutAddMenuEntry("light0 +y", 3);
	glutAddMenuEntry("light0 -y", 4);
	glutAddMenuEntry("light0 +z", 5);
	glutAddMenuEntry("light0 -z", 6);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	GLint DoMenuID3 = glutCreateMenu(DoMenuLight1);
	glutSetMenu(DoMenuID3);
	glutAddMenuEntry("light1 +x", 1);
	glutAddMenuEntry("light1 -x", 2);
	glutAddMenuEntry("light1 +y", 3);
	glutAddMenuEntry("light1 -y", 4);
	glutAddMenuEntry("light1 +z", 5);
	glutAddMenuEntry("light1 -z", 6);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);

	glutDisplayFunc(DoDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}
