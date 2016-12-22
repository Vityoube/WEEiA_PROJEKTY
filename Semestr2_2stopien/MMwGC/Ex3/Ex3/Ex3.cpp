// Ex3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Spring.h"
#include "Sphere.h"


using namespace std;
GLuint texture_id;

static Spring spring;
static Sphere sphere;

double graphicLeft = 0.0, graphicRight = 100.0, graphicTop = 100.0, graphicBottom = -100.0, graphicNear = 2.0, graphicFar = 25.0;

GLuint load_texture(const char* filename) {
	FIBITMAP * bitmap = NULL;
	int x, y;
	RGBQUAD rgbquad;
	FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(filename);
	bitmap = FreeImage_Load(fif, filename, JPEG_DEFAULT);
	FREE_IMAGE_TYPE type = FreeImage_GetImageType(bitmap);
	BITMAPINFOHEADER *header = FreeImage_GetInfoHeader(bitmap);

	int imageHeight = FreeImage_GetHeight(bitmap), imageWidth = FreeImage_GetWidth(bitmap);


	int scanLineWidh = ((3 * imageWidth) % 4 == 0) ? 3 * imageWidth : ((3 * imageWidth) / 4) * 4 + 4;
	unsigned char * texels = (GLubyte*)calloc(imageHeight*scanLineWidh, sizeof(GLubyte));
	for (x = 0; x<imageWidth; x++)
		for (y = 0; y<imageHeight; y++)
		{
			FreeImage_GetPixelColor(bitmap, x, y, &rgbquad);

			texels[(y*scanLineWidh + 3 * x)] = ((GLubyte*)&rgbquad)[2];
			texels[(y*scanLineWidh + 3 * x) + 1] = ((GLubyte*)&rgbquad)[1];
			texels[(y*scanLineWidh + 3 * x) + 2] = ((GLubyte*)&rgbquad)[0];
		}

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imageWidth, imageHeight, 0, GL_RGB,
		GL_UNSIGNED_BYTE, texels);
	free(texels);
	return texture_id;
}
void initWindow(int width, int height) {
	texture_id = load_texture("wood.jpg");
	const float ar = (float)width / (float)height;
	graphicLeft = -ar * 100;
	graphicRight = ar * 100;
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(graphicLeft, graphicRight, graphicBottom, graphicTop, graphicNear, graphicFar);
	glEnable(GL_DEPTH);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
}

void resizeWindow( int width, int height) {
	const float ar = (float)width / (float)height;
	graphicLeft = -ar * 100;
	graphicRight = ar * 100;
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(graphicLeft, graphicRight, graphicBottom, graphicTop, graphicNear, graphicFar);
	glEnable(GL_DEPTH);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	
	
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	sphere.set_texture(texture_id);
	sphere.draw();
	spring.draw();	
	glutSwapBuffers();
}


int main(int argc, char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STEREO);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);	
	glutCreateWindow("Exercise 3");
	initWindow(600, 600);	

	
	glutReshapeFunc(resizeWindow);
	glutDisplayFunc(renderScene);
	
	glutMainLoop();
    return 0;
}


