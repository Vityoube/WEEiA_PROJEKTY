// Ex3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GL\glut.h"
#include "FreeImage.h"
#include <iostream>

double graphicLeft = 0.0, graphicRight = 100.0, graphicTop = 100.0, graphicBottom = -100.0, graphicNear = 2.0, graphicFar = 25.0;
GLdouble sphereRadius=20.0;
GLuint sphereSlices = 100, sphereStacks = 100;
GLuint textureID;
FILE* image;


FIBITMAP *loadImage(const char * filename) {
	FIBITMAP *dib1 = NULL;

	FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(filename);

	dib1 = FreeImage_Load(fif, filename, JPEG_DEFAULT);
	if (!dib1)
	{
		std::cerr << "Error loading image" << std::endl;
		exit(0);

	}
	return dib1;
}

GLuint loadTexture(FIBITMAP * dib1) {
	GLuint tex_id = 0;
	int x, y;
	int height, width;

	RGBQUAD rgbquad;


	FREE_IMAGE_TYPE type;
	BITMAPINFOHEADER *header;

	type = FreeImage_GetImageType(dib1);


	height = FreeImage_GetHeight(dib1);
	width = FreeImage_GetWidth(dib1);

	header = FreeImage_GetInfoHeader(dib1);
	int scanLineWidh = ((3 * width) % 4 == 0) ? 3 * width : ((3 * width) / 4) * 4 + 4;
	unsigned char * texels = (GLubyte*)calloc(height*scanLineWidh, sizeof(GLubyte));
	for (x = 0; x<width; x++)
		for (y = 0; y<height; y++)
		{
			FreeImage_GetPixelColor(dib1, x, y, &rgbquad);

			texels[(y*scanLineWidh + 3 * x)] = ((GLubyte*)&rgbquad)[2];
			texels[(y*scanLineWidh + 3 * x) + 1] = ((GLubyte*)&rgbquad)[1];
			texels[(y*scanLineWidh + 3 * x) + 2] = ((GLubyte*)&rgbquad)[0];
		}

	glGenTextures(1, &tex_id);
	glBindTexture(GL_TEXTURE_2D, tex_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		width, height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, texels);
	free(texels);

	return tex_id;
}
void resizeScene(int width, int height) {
	const float ar = (float)width / (float)height;
	graphicLeft = -ar * 100;
	graphicRight = ar * 100;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(graphicLeft, graphicRight, graphicBottom, graphicTop, graphicNear, graphicFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTranslated(0.0, 0.0, -2.0);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glutSolidSphere(sphereRadius, sphereSlices, sphereStacks);
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Exercise 3");

	glutReshapeFunc(resizeScene);
	glutDisplayFunc(renderScene);
	glutMainLoop();
    return 0;
}

