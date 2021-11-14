#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>

float pos_x = 0, pos_y = 0;
bool isRight = true;

// блок объ€влений функций
void renderScene(void);
void processKeys(unsigned char key, int x, int y); // определение фнкции перед фукнцией main

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL Start Application");
	glutDisplayFunc(renderScene);

	glutKeyboardFunc(processKeys);

	glutMainLoop();
	return 0;
}

void processKeys(unsigned char key, int x, int y) {
	if (key == 100) {
		pos_x = pos_x + 0.1;
		isRight = false;
	}
	if (key == 97) {
		pos_x = pos_x - 0.1;
		isRight = true;
	}

	if (key == 115) {
		pos_y = pos_y - 0.1;
	}

	if (key == 119) {
		pos_y = pos_y + 0.1;
	}
	if (key == 13)
		exit(0); // close app

	glutPostRedisplay(); // отрисовка
}

void drawPez(float r, float g, float b) {

	glBegin(GL_QUADS);

	//трава
	glColor3f(r, g + 0.4, b);
	glVertex2f(-2, -0.4);
	glVertex2f(2, -0.4);
	glVertex2f(2, -2);
	glVertex2f(-2, -2);

	//небо
	glColor3f(r, g - 0.2, b + 0.5);
	glVertex2f(-2, -0.4);
	glVertex2f(2, -0.4);
	glVertex2f(2, 2);
	glVertex2f(-2, 2);

	//морэ
	glColor3f(0.4, 0.2, 1);
	glVertex2f(-2, -0.4);
	glVertex2f(2, -0.4);
	glVertex2f(2, -0.1);
	glVertex2f(-2, -0.1);

	glEnd();

}

void drawDom(float r, float g, float b) {
	glPushMatrix();
	if (isRight)
		glRotatef(180, 0, 0, 1);

	glBegin(GL_QUADS);

	//дом
	glColor3f(r, g, b);
	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.8, 0.2);
	glVertex2f(-0.2, 0.2);
	glVertex2f(-0.2, -0.5);

	//окно
	glColor3f(0.2, 0.2, 1);
	glVertex2f(-0.75, -0.25);
	glVertex2f(-0.75, 0.05);
	glVertex2f(-0.55, 0.05);
	glVertex2f(-0.55, -0.25);

	//дверка
	glColor3f(1, 0.2, 0.4);
	glVertex2f(-0.45, -0.5);
	glVertex2f(-0.45, -0.1);
	glVertex2f(-0.25, -0.1);
	glVertex2f(-0.25, -0.5);

	//труба
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(-0.35, 0.3);
	glVertex2f(-0.35, 0.5);
	glVertex2f(-0.25, 0.5);
	glVertex2f(-0.25, 0.3);

	glEnd();

	glBegin(GL_TRIANGLES);

	//крыша
	glColor3f(0.7, 0.2, 0.2);
	glVertex2f(-0.9, 0.2);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.1, 0.2);

	glEnd();
	glPopMatrix();
}

void drawKorabl(float r, float g, float b) {

	glBegin(GL_QUADS);

	//лододка
	glColor3f(r, g, b);
	glVertex2f(0, 0);
	glVertex2f(0.1, -0.2);
	glVertex2f(0.6, -0.2);
	glVertex2f(0.7, 0);

	glEnd();

	glBegin(GL_TRIANGLES);

	//палуба
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(0.4, 0);
	glVertex2f(0.5, 0);
	glVertex2f(0.4, 0.4);

	//палуба
	glColor3f(1, 1, 1);
	glVertex2f(0.4, 0);
	glVertex2f(0.1, 0.1);
	glVertex2f(0.4, 0.4);

	glEnd();

}

void drawCat(float r, float g, float b) {

	glBegin(GL_QUADS);

	//ножки кожки
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(0.3, -0.95);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(0.3, -0.75);
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(0.4, -0.95);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(0.4, -0.8);

	glEnd();

	glBegin(GL_TRIANGLES);

	//телоло
	glColor3f(r, g, b);
	glVertex2f(0.3, -0.6);
	glVertex2f(0.25, -0.9);
	glVertex2f(0.5, -0.9);

	//хвист
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(0.55, -0.65);
	glVertex2f(0.45, -0.7);
	glVertex2f(0.5, -0.9);

	//кисье лицо
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(0.2, -0.55);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(0.4, -0.55);
	glColor3f(1, 1, 1);
	glVertex2f(0.3, -0.7);

	//глазек
	glColor3f(0.2, 0.9, 0.2);
	glVertex2f(0.25, -0.6);
	glVertex2f(0.28, -0.6);
	glVertex2f(0.255, -0.61);

	//газек 3
	glColor3f(0.2, 0.9, 0.2);
	glVertex2f(0.33, -0.6);
	glVertex2f(0.36, -0.6);
	glVertex2f(0.355, -0.61);

	//ушко
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(0.2, -0.55);
	glVertex2f(0.25, -0.5);
	glVertex2f(0.3, -0.55);

	//ушко
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(0.4, -0.55);
	glVertex2f(0.35, -0.5);
	glVertex2f(0.3, -0.55);

	//носик
	glColor3f(1, 0.6, 0.6);
	glVertex2f(0.285, -0.65);
	glVertex2f(0.315, -0.65);
	glVertex2f(0.30, -0.67);

	glEnd();

}

void drawSobaka(float x, float y, bool isRight) {

	glPushMatrix();
	glTranslatef(x, y, 0);
	glBegin(GL_QUADS);

	//ножки собаки 2 по -08 (-9-8-9-8) и по -05
	glColor3f(0.4, 0.4, 0.4);
	glVertex2f(-0.8, -0.9);
	glVertex2f(-0.8, -0.8);
	glVertex2f(-0.5, -0.9);
	glVertex2f(-0.5, -0.8);

	//тело собаки
	glColor3f(0.8, 0.4, 0.4);
	glVertex2f(-0.8, -0.85);
	glVertex2f(-0.8, -0.65);
	glVertex2f(-0.5, -0.65);
	glVertex2f(-0.5, -0.85);

	//голова собаки
	glColor3f(0.8, 0.4, 0.4);
	glVertex2f(-0.3, -0.7);
	glVertex2f(-0.4, -0.6);
	glVertex2f(-0.5, -0.6);
	glVertex2f(-0.5, -0.75);

	glEnd();

	glBegin(GL_TRIANGLES);

	//ухо песа
	glColor3f(0.7, 0.2, 0.7);
	glVertex2f(-0.55, -0.7);
	glVertex2f(-0.5, -0.6);
	glVertex2f(-0.45, -0.7);

	//глаз
	glColor3f(0, 0, 0);
	glVertex2f(-0.44, -0.64);
	glVertex2f(-0.44, -0.65);
	glVertex2f(-0.45, -0.645);

	//хвост
	glColor3f(0.7, 0.2, 0.7);
	glVertex2f(-0.8, -0.65);
	glVertex2f(-0.85, -0.8);
	glVertex2f(-0.95, -0.7);

	glEnd();
	glPopMatrix();

}

void drawElka(float g) {

	glBegin(GL_TRIANGLES);

	//палуба
	glColor3f(0.1, g, 0.4);
	glVertex2f(-0.8, -0.1);
	glVertex2f(-0.7, 0);
	glVertex2f(-0.6, -0.1);

	//палуба
	glColor3f(0.1, g, 0.5);
	glVertex2f(-0.8, -0.2);
	glVertex2f(-0.7, -0.1);
	glVertex2f(-0.6, -0.2);

	//палуба
	glColor3f(0.1, g, 0.5);
	glVertex2f(-0.8, -0.3);
	glVertex2f(-0.7, -0.2);
	glVertex2f(-0.6, -0.3);

	glEnd();

	glBegin(GL_QUADS);

	//лододка
	glColor3f(0.8, 0.6, 0.5);
	glVertex2f(-0.75, -0.3);
	glVertex2f(-0.75, -0.4);
	glVertex2f(-0.65, -0.4);
	glVertex2f(-0.65, -0.3);

	glEnd();

}

void drawPtica(float t) {
	glBegin(GL_TRIANGLES);

	//палуба 08
	glColor3f(t, 0.8, 0.8);
	glVertex2f(0.5, -0.6);
	glVertex2f(0.7, -0.9);
	glVertex2f(0.9, -0.8);

	//палуба
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(0.6, -0.65);
	glVertex2f(0.7, -0.8);
	glVertex2f(0.9, -0.8);

	//палуба
	glColor3f(0.9, 0.3, 0.3);
	glVertex2f(0.65, -0.95);
	glVertex2f(0.7, -0.9);
	glVertex2f(0.75, -0.95);

	//палуба
	glColor3f(0.8, t, t);
	glVertex2f(0.4, -0.6);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, -0.6);

	//палуба
	glColor3f(t, 0.3, 0.3);
	glVertex2f(0.3, -0.6);
	glVertex2f(0.4, -0.6);
	glVertex2f(0.45, -0.55);

	glEnd();
}

void grafik() {

	glPushMatrix();
	glScalef(0.5, 0.5, 0);

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(0, -10);
	glVertex2f(0, 10);
	glVertex2f(10, 0);
	glVertex2f(-10, 0);
	glEnd();

	glPushMatrix();
	glScalef(0.1, 0.1, 0);
	glBegin(GL_LINE_STRIP);
	for (float i = -100; i < 100; i += 0.1) {
		glColor3f(1, 1, 1);
		glVertex2f(i, -2*i*i+3*i-1);
	}
	glEnd();
	glPopMatrix;
}


void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функци€ должна быть первой в renderScene

	drawSobaka(pos_x, pos_y, isRight);

	glutSwapBuffers();
}