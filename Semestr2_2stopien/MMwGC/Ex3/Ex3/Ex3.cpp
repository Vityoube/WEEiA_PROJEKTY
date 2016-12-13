// Ex3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
<<<<<<< HEAD
=======
#include "gl3.h"
#include "GL\glut.h"
#include "FreeImage.h"
>>>>>>> d9481e3ea31403e4f55c842bc2624ccfe7b3a257
#include <iostream>
#include "GL\freeglut.h"
#include "FreeImage.h"

double graphicLeft = 0.0, graphicRight = 100.0, graphicTop = 100.0, graphicBottom = -100.0, graphicNear = 2.0, graphicFar = 25.0;
GLdouble sphereRadius=20.0;
GLuint sphereSlices = 100, sphereStacks = 100;
<<<<<<< HEAD
GLuint textureID;
GLfloat rotateAngle=0.0f;
bool rmbPressed;

using namespace std;

void loadTexture(const char * filename) {
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
=======

GLuint tex_id;

GLuint load_texture(std::string filenameString, GLenum minificationFilter = GL_LINEAR, GLenum magnificationFilter = GL_LINEAR)
{
	// Get the filename as a pointer to a const char array to play nice with FreeImage
	glMatrixMode(GL_TEXTURE);
	const char* filename = filenameString.c_str();

	// Determine the format of the image.
	// Note: The second paramter ('size') is currently unused, and we should use 0 for it.
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename, 0);

	// Image not found? Abort! Without this section we get a 0 by 0 image with 0 bits-per-pixel but we don't abort, which
	// you might find preferable to dumping the user back to the desktop.
	if (format == -1)
	{
		std::cout << "Could not find image: " << filenameString.c_str() << " - Aborting." << std::endl;
		exit(-1);
	}

	// Found image, but couldn't determine the file format? Try again...
	if (format == FIF_UNKNOWN)
	{
		std::cout << "Couldn't determine file format - attempting to get from file extension..." << std::endl;

		// ...by getting the filetype from the filename extension (i.e. .PNG, .GIF etc.)
		// Note: This is slower and more error-prone that getting it from the file itself,
		// also, we can't use the 'U' (unicode) variant of this method as that's Windows only.
		format = FreeImage_GetFIFFromFilename(filename);

		// Check that the plugin has reading capabilities for this format (if it's FIF_UNKNOWN,
		// for example, then it won't have) - if we can't read the file, then we bail out =(
		if (!FreeImage_FIFSupportsReading(format))
		{
			std::cout << "Detected image format cannot be read!" << std::endl;
			exit(-1);
		}
	}

	// If we're here we have a known image format, so load the image into a bitap
	FIBITMAP* bitmap = FreeImage_Load(format, filename);

	// How many bits-per-pixel is the source image?
	int bitsPerPixel = FreeImage_GetBPP(bitmap);

	// Convert our image up to 32 bits (8 bits per channel, Red/Green/Blue/Alpha) -
	// but only if the image is not already 32 bits (i.e. 8 bits per channel).
	// Note: ConvertTo32Bits returns a CLONE of the image data - so if we
	// allocate this back to itself without using our bitmap32 intermediate
	// we will LEAK the original bitmap data, and valgrind will show things like this:
	//
	// LEAK SUMMARY:
	//  definitely lost: 24 bytes in 2 blocks
	//  indirectly lost: 1,024,874 bytes in 14 blocks    <--- Ouch.
	//
	// Using our intermediate and cleaning up the initial bitmap data we get:
	//
	// LEAK SUMMARY:
	//  definitely lost: 16 bytes in 1 blocks
	//  indirectly lost: 176 bytes in 4 blocks
	//
	// All above leaks (192 bytes) are caused by XGetDefault (in /usr/lib/libX11.so.6.3.0) - we have no control over this.
	//
	FIBITMAP* bitmap32;
	if (bitsPerPixel == 32)
	{
		std::cout << "Source image has " << bitsPerPixel << " bits per pixel. Skipping conversion." << std::endl;
		bitmap32 = bitmap;
	}
	else
	{
		std::cout << "Source image has " << bitsPerPixel << " bits per pixel. Converting to 32-bit colour." << std::endl;
		bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
	}

	// Some basic image info - strip it out if you don't care
	int imageWidth = FreeImage_GetWidth(bitmap32);
	int imageHeight = FreeImage_GetHeight(bitmap32);
	std::cout << "Image: " << filenameString.c_str() << " is size: " << imageWidth << "x" << imageHeight << "." << std::endl;

	// Get a pointer to the texture data as an array of unsigned bytes.
	// Note: At this point bitmap32 ALWAYS holds a 32-bit colour version of our image - so we get our data from that.
	// Also, we don't need to delete or delete[] this textureData because it's not on the heap (so attempting to do
	// so will cause a crash) - just let it go out of scope and the memory will be returned to the stack.
	GLubyte* textureData = FreeImage_GetBits(bitmap32);

	// Generate a texture ID and bind to it
	GLuint tempTextureID;
	glGenTextures(1, &tempTextureID);
	glBindTexture(GL_TEXTURE_2D, tempTextureID);

	// Construct the texture.
	// Note: The 'Data format' is the format of the image data as provided by the image library. FreeImage decodes images into
	// BGR/BGRA format, but we want to work with it in the more common RGBA format, so we specify the 'Internal format' as such.
	glTexImage2D(GL_TEXTURE_2D,    // Type of texture
		0,                // Mipmap level (0 being the top level i.e. full size)
		GL_RGBA,          // Internal format
		imageWidth,       // Width of the texture
		imageHeight,      // Height of the texture,
		0,                // Border in pixels
		GL_BGRA_EXT,          // Data format
		GL_UNSIGNED_BYTE, // Type of texture data
		textureData);     // The image data to use for this texture

						  // Specify our minification and magnification filters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minificationFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magnificationFilter);

	// If we're using MipMaps, then we'll generate them here.
	// Note: The glGenerateMipmap call requires OpenGL 3.0 as a minimum.
	if (minificationFilter == GL_LINEAR_MIPMAP_LINEAR ||
		minificationFilter == GL_LINEAR_MIPMAP_NEAREST ||
		minificationFilter == GL_NEAREST_MIPMAP_LINEAR ||
		minificationFilter == GL_NEAREST_MIPMAP_NEAREST)
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, imageWidth, imageHeight,  GL_RGBA,GL_UNSIGNED_BYTE,textureData);

	}

	// Check for OpenGL texture creation errors
	GLenum glError = glGetError();
	if (glError)
	{
		std::cout << "There was an error loading the texture: " << filenameString.c_str() << std::endl;

		switch (glError)
		{
		case GL_INVALID_ENUM:
			std::cout << "Invalid enum." << std::endl;
			break;

		case GL_INVALID_VALUE:
			std::cout << "Invalid value." << std::endl;
			break;
>>>>>>> d9481e3ea31403e4f55c842bc2624ccfe7b3a257

		case GL_INVALID_OPERATION:
			std::cout << "Invalid operation." << std::endl;

		default:
			std::cout << "Unrecognised GLenum." << std::endl;
			break;
		}

<<<<<<< HEAD
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
=======
	}

	// Unload the 32-bit colour bitmap
	FreeImage_Unload(bitmap32);
>>>>>>> d9481e3ea31403e4f55c842bc2624ccfe7b3a257

	// If we had to do a conversion to 32-bit colour, then unload the original
	// non-32-bit-colour version of the image data too. Otherwise, bitmap32 and
	// bitmap point at the same data, and that data's already been free'd, so
	// don't attempt to free it again! (or we'll crash).
	if (bitsPerPixel != 32)
	{
		FreeImage_Unload(bitmap);
	}

	// Finally, return the texture ID
	glLoadIdentity();
	return tempTextureID;
}

<<<<<<< HEAD
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		imageWidth, imageHeight, 0, GL_RGB,
		GL_UNSIGNED_BYTE, texels);
	free(texels);
}

void initWindow(int width, int height) {
	loadTexture("wood.jpg");
=======

void init() {
	int width = 600, height = 600;
	const float ar = (float)width / (float)height;
	graphicLeft = -ar * 100;
	graphicRight = ar * 100;
>>>>>>> d9481e3ea31403e4f55c842bc2624ccfe7b3a257
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(graphicLeft, graphicRight, graphicBottom, graphicTop, graphicNear, graphicFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
<<<<<<< HEAD
	glEnable(GL_DEPTH);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	
=======
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	FreeImage_Initialise(true);
>>>>>>> d9481e3ea31403e4f55c842bc2624ccfe7b3a257
}

void resizeWindow( int width, int height) {
	const float ar = (float)width / (float)height;
	graphicLeft = -ar * 100;
	graphicRight = ar * 100;
	glClearColor(0.0, 0.0, 0.0, 0.0);
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
	glTranslated(0.0, 0.0, -2.0);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glutSolidSphere(sphereRadius, sphereSlices, sphereStacks);
<<<<<<< HEAD
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
=======
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
>>>>>>> d9481e3ea31403e4f55c842bc2624ccfe7b3a257
	glutSwapBuffers();
}


int main(int argc, char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STEREO);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);	
	glutCreateWindow("Exercise 3");
<<<<<<< HEAD
	initWindow(600, 600);	

	
	glutReshapeFunc(resizeWindow);
	glutDisplayFunc(renderScene);
	
	glutMainLoop();
    return 0;
=======
	init();
	tex_id = load_texture("wood.jpg");
	glutReshapeFunc(resizeScene);	
	glutDisplayFunc(renderScene);	
	glutMainLoop();	
	FreeImage_DeInitialise();
	return 0;
>>>>>>> d9481e3ea31403e4f55c842bc2624ccfe7b3a257
}


