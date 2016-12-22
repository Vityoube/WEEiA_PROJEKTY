#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

void Sphere::draw() {
	glEnable(GL_TEXTURE_2D);
	glTranslated(0.0, 0.0, -2.0);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glutSolidSphere(radius, slices, stacks);
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void Sphere::set_texture(GLuint texture_id) {
	this->texture_id = texture_id;
}


