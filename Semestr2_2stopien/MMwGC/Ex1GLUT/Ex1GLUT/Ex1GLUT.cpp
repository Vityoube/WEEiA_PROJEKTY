// Ex1GLUT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "GL\GL.H"
#include "GL\glut.h"
#include <stdlib.h>

void myDisplay()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex2f(100.0f, 50.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glVertex2f(450.0f, 400.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glEnd();
	
	glFlush();
}

void myInit()
{
	glClearColor(0.0, 0.0, 0.0,0.0);
	glViewport(0, 0, 300, 300);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500 * 1.2, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My Window");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
    return 0;
}

