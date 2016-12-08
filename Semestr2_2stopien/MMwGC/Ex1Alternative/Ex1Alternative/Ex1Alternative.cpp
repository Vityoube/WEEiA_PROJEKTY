// Ex1Alternative.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Window.h"


int main()
{
	Window::fullScreen = false;
	Window::title = "OpenGL exercise 1";
	Window window(640, 480);

	while (!glfwWindowShouldClose(Window::window))
	{
		Window::closeWindow();
		Window::toggleFullScreen();

		glfwSwapBuffers(Window::window);
		glfwPollEvents();
	}
	glfwDestroyWindow(Window::window);
    return 0;
}

