#pragma once
#include "stdafx.h"
class Sphere
{
protected:
	
	const GLuint slices = 100, stacks = 100;	
public: 
	const GLdouble radius = 10.0f;
	GLuint texture_id;
public:
	Sphere();
	~Sphere();
	void draw();
	void set_texture(GLuint texture_id);
	
};

