#pragma once

#include "stdafx.h"
#include "Sphere.h"

class Spring
{
protected:
	const GLfloat U_STEP = (GLfloat)(2 * PI / 10), T_STEP = (GLfloat)(8 * PI / 10);
	const GLfloat spring_size = 10.0f;
	GLfloat spring_X_step = 0.0f, spring_Y_step = 5.0f, spring_Z_step = 0.0f;
	GLfloat u, t;
	int n = 200;
public:
	Spring();
	~Spring();
	
	void draw();
};

