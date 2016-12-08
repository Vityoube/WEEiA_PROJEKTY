#pragma once

#include "stdafx.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <iostream>


class Window
{
public:
	static GLFWwindow* window;
	static bool fullScreen;
	static std::string title;
	static float width;
	static float height;
	static float FOV;
	static float P1;
	static float P2;
	static float aspect;

	static glm::mat4 perspective;
	static glm::mat4 view;
	
	static glm::vec3 cameraPosition;
	static glm::vec3 cameraDirection;
	static glm::vec3 cameraUp;
	static glm::vec3 cameraRight;

	Window(float width, float height);
	~Window();

	static void windowSizeCallback(GLFWwindow* , int widthWindow, int heightWindow);
	static void closeWindow();
	static void toggleFullScreen();
};

