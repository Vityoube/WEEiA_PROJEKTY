// Ex2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "GL\glut.h"
#include <math.h>

const int windowHeight = 600;
const int windowWidth = 600;
const float graphicLeft = -150.0;
const float graphicRight = 150.0;
const float graphicBottom = -150.0;
const float graphicTop = 150.0;

const int triangleLength=15;

float blueTriangleRotateAngle = 0.0f;
float greenOrangeTriangleRotateAngle = 360.0f;
float pinkRedYellowTriangleRotateAngle = 0.0f;

float move_bX = 0.0f; float move_bY = 0.0f; float move_bDirection = 1.0f;
float move_goX = 0.0f; float move_goY = 0.0f; float move_goDirection = 1.0f;

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3,float red, float green, float blue) {
	glBegin(GL_TRIANGLES);
	glColor4f(red, green, blue, 1.0f);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}
void rotateTriangle(float x, float y, float rotateAngle) {
	glTranslatef(x, y,0.0f);
	glRotatef(rotateAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-x, -y, 0.0f);
}
void drawBlueTriangles(){		
	//Blue
	glPushMatrix();
	rotateTriangle(triangleLength / 3, triangleLength / 3,blueTriangleRotateAngle);
	glTrslanatef(move_bX, move_bY,0.0f);
	drawTriangle(0.0f, 0.0f, triangleLength, 0.0f, 0.0f, triangleLength, 0.0f, 0.0f, 1.0f);
	glPopMatrix(); 

	glPushMatrix();
	rotateTriangle(-triangleLength / 3, triangleLength / 3, blueTriangleRotateAngle);
	glTranslatef(-move_bX, move_bY, 0.0f);
	drawTriangle(0.0f, 0.0f, -triangleLength, 0.0f, 0.0f, triangleLength, 0.0f, 0.0f, 1.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(-triangleLength / 3, -triangleLength / 3, blueTriangleRotateAngle);
	glTranslatef(-move_bX, -move_bY, 0.0f);
	drawTriangle(0.0f, 0.0f, -triangleLength, 0.0f, 0.0f, -triangleLength, 0.0f, 0.0f, 1.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(triangleLength / 3, -triangleLength / 3, blueTriangleRotateAngle);
	glTranslatef(move_bX, -move_bY, 0.0f);
	drawTriangle(0.0f, 0.0f, triangleLength, 0.0f, 0.0f, -triangleLength, 0.0f, 0.0f, 1.0f);
	glPopMatrix();

	glutSwapBuffers();

}

void drawGreenAndOrangeTriangles() {

	//Green
	glPushMatrix();
	rotateTriangle(-4*triangleLength/3,triangleLength/3,greenOrangeTriangleRotateAngle);
	glTranslatef(-move_goX, move_goY, 0.0f);
	drawTriangle(-2*triangleLength, 0.0f, -triangleLength, 0.0f, -triangleLength, triangleLength, 0.0f, 1.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(triangleLength/3, 4*triangleLength/3,greenOrangeTriangleRotateAngle);
	glTranslatef(move_goX, move_goY, 0.0f);
	drawTriangle(0.0f, triangleLength, triangleLength, triangleLength, 0.0f, triangleLength*2, 0.0f, 1.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(4*triangleLength/3, -triangleLength / 3, greenOrangeTriangleRotateAngle);
	glTranslatef(move_goX, -move_goY, 0.0f);
	drawTriangle(triangleLength, 0.0f, triangleLength*2, 0.0f, triangleLength, -triangleLength, 0.0f, 1.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(-triangleLength/3, -4*triangleLength/3, greenOrangeTriangleRotateAngle);
	glTranslatef(-move_goX, -move_goY, 0.0f);
	drawTriangle(-triangleLength,- triangleLength, 0.0f, -triangleLength, 0.0f, -2*triangleLength, 0.0f, 1.0f, 0.0f);
	glPopMatrix();

	//Orange
	glPushMatrix();
	rotateTriangle(-4*triangleLength / 3, -triangleLength / 3, greenOrangeTriangleRotateAngle);
	glTranslatef(-move_goX, -move_goY, 0.0f);
	drawTriangle(-triangleLength, -triangleLength, -triangleLength, 0.0f, -2*triangleLength, 0.0f, 1.0f, 0.6f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(-triangleLength / 3, 4 * triangleLength / 3, greenOrangeTriangleRotateAngle);
	glTranslatef(-move_goX, move_goY, 0.0f);
	drawTriangle(-triangleLength, triangleLength, 0.0f, triangleLength*2, 0.0f, triangleLength, 1.0f, 0.6f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(4*triangleLength / 3,triangleLength / 3, greenOrangeTriangleRotateAngle);
	glTranslatef(move_goX, move_goY, 0.0f);
	drawTriangle(triangleLength, triangleLength, triangleLength, 0.0f, 2 * triangleLength, 0.0f, 1.0f, 0.6f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(triangleLength / 3, -4 * triangleLength / 3, greenOrangeTriangleRotateAngle);
	glTranslatef(move_goX, -move_goY, 0.0f);
	drawTriangle(triangleLength, -triangleLength, 0.0f, -triangleLength, 0.0f, -2*triangleLength, 1.0f, 0.6f, 0.0f);
	glPopMatrix();

}

void drawRedPinkYellowTriangles() {
	
	//Red
	glPushMatrix();
	rotateTriangle(-7*triangleLength / 3, triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(-2*triangleLength, triangleLength, -2*triangleLength, 0.0f, -3 * triangleLength, 0.0f, 1.0f, 0.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(triangleLength / 3, 7 * triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(triangleLength, 2*triangleLength, 0.0f, 2*triangleLength, 0.0f, 3*triangleLength, 1.0f, 0.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(7*triangleLength / 3, - triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(2*triangleLength, 0.0f,2*triangleLength, -triangleLength, 3*triangleLength, 0.0f, 1.0f, 0.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(- triangleLength / 3, -7*triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(0.0f, -2*triangleLength, - triangleLength, -2*triangleLength, 0.0f,-3 * triangleLength, 1.0f, 0.0f, 0.0f);
	glPopMatrix();

	//Pink
	glPushMatrix();
	rotateTriangle(-7 * triangleLength / 3, -triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(-2 * triangleLength, -triangleLength, -2 * triangleLength, 0.0f, -3 * triangleLength, 0.0f, 1.0f, 0.7f, 0.8f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(-triangleLength / 3, 7 * triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(-triangleLength, 2 * triangleLength, 0.0f, 2 * triangleLength, 0.0f, 3 * triangleLength, 1.0f, 0.7f, 0.8f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(7 * triangleLength / 3, triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(2 * triangleLength, 0.0f, 2 * triangleLength, triangleLength, 3 * triangleLength, 0.0f, 1.0f, 0.7f, 0.8f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(triangleLength / 3, -7 * triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(0.0f, -2 * triangleLength, triangleLength, -2 * triangleLength, 0.0f, -3 * triangleLength, 1.0f, 0.7f, 0.8f);
	glPopMatrix();


	//Yellow
	glPushMatrix();
	rotateTriangle(-4 * triangleLength / 3, 4*triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(-2 * triangleLength, triangleLength, - triangleLength, triangleLength, - triangleLength, 2*triangleLength, 1.0f, 1.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(4 * triangleLength / 3, 4 * triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(2 * triangleLength, triangleLength, triangleLength, triangleLength, triangleLength, 2 * triangleLength, 1.0f, 1.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(4 * triangleLength / 3, -4 * triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(2 * triangleLength, -triangleLength, triangleLength, -triangleLength, triangleLength, -2 * triangleLength, 1.0f, 1.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	rotateTriangle(-4 * triangleLength / 3, -4 * triangleLength / 3, pinkRedYellowTriangleRotateAngle);
	drawTriangle(-2 * triangleLength, -triangleLength, -triangleLength, -triangleLength, -triangleLength, -2 * triangleLength, 1.0f, 1.0f, 0.0f);
	glPopMatrix();

}

void display() {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	drawBlueTriangles();
	drawGreenAndOrangeTriangles();
	drawRedPinkYellowTriangles();

	glFlush();
}

void init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(graphicLeft, graphicRight, graphicBottom, graphicTop);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
	}
}

void update(int value) {
	blueTriangleRotateAngle += 18.0f;
	greenOrangeTriangleRotateAngle -= 6.0f;
	pinkRedYellowTriangleRotateAngle += 2.0f;
	move_bX += move_bDirection*3*triangleLength/(10*blueTriangleRotateAngle); 
	move_bY += move_bDirection * 3 * triangleLength / (10 * blueTriangleRotateAngle);

	move_goX+= move_goDirection * 3 * triangleLength / (10 * (360-greenOrangeTriangleRotateAngle));
	move_goY+= move_goDirection * 3 * triangleLength / (10 * (360-greenOrangeTriangleRotateAngle));
	if (blueTriangleRotateAngle >= 360.0f) {
		blueTriangleRotateAngle -= 360.0f;
	}
	if (greenOrangeTriangleRotateAngle <= 0.0f) {
		greenOrangeTriangleRotateAngle += 360.0f;
	}
	if (pinkRedYellowTriangleRotateAngle >= 360.0f) {
		pinkRedYellowTriangleRotateAngle -= 360.0f;
	}
	if (move_bX >= 3 *triangleLength)
		move_bDirection = -1.0f;
	else if (move_bX<=0.0f)
		move_bDirection = 1.0f;
	if (move_goX >= 3 * triangleLength)
		move_goDirection = -1.0f;
	else if (move_goX<=2*triangleLength)
		move_goDirection = 1.0f;
	glutPostRedisplay();
	glutTimerFunc(60, update, 0);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Exercise 2");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(25,update,0);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();
    return 0;
}

