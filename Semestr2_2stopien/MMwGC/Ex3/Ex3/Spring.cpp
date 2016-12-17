#include "stdafx.h"
#include "Spring.h"


Spring::Spring()
{
}


Spring::~Spring()
{
}

void Spring::draw() {
	glEnable(GL_DEPTH);
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(0.0, 0.0, -2.0);
	GLfloat spring_X = 0.0f, spring_Y = 0.0f, spring_Z = 0.0f;
	glBegin(GL_LINE_STRIP);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	for (t = 0; t <= 8 * PI; t += T_STEP) {
		for (u = 0; u <= 2 * PI; u += U_STEP) {
			spring_X_step = (3 + (cos(u / 180)));
			spring_Y_step = (3 + (sin(u / 180)));
			spring_Z_step = (sin(u / 180));
			spring_X = (cos(t / 180))*spring_X_step;
			spring_Y = (sin(t / 180))*spring_Y_step;
			spring_Z = (0.6*t) + spring_Z_step;
			glVertex3f(spring_X, spring_Y, spring_Z);
		}
	}
	glEnd();
	glPopMatrix();
}
