#include "stdafx.h"
#include "Window.h"


GLFWwindow *Window::window;
bool Window::fullScreen = false;
std::string Window::title = "";
float Window::width = 0;
float Window::height = 0;
float Window::aspect = 0;
float Window::P1 = 0.1f;
float Window::P2 = 20.0f;
float Window::FOV = 360.0f;

glm::mat4 Window::perspective = glm::mat4(1.0f);
glm::mat4 Window::view = glm::mat4(1.0f);

glm::vec3 Window::cameraPosition = glm::vec3(0.0f, 0.0f, 2.0f);
glm::vec3 Window::cameraDirection = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 Window::cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
glm::vec3 Window::cameraUp = glm::cross(Window::cameraRight, Window::cameraDirection);

Window::Window(float width, float height)
{
	if (glfwInit() == 0)
	{
		std::cout << "Can't initialize GLFW" << std::endl;
	}
	if (!fullScreen)
		glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	else
	{
		const GLFWvidmode* videomod = glfwGetVideoMode(glfwGetPrimaryMonitor());
		fullScreen = true;
		glfwCreateWindow(videomod->width, videomod->height, title.c_str(), glfwGetPrimaryMonitor(), nullptr);
	}
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Can't initialize GLEW" << std::endl;
	}
	glfwSetWindowSizeCallback(window, windowSizeCallback);
}


Window::~Window()
{
}

void Window::windowSizeCallback(GLFWwindow *, int widthWindow, int heightWindow)
{
	width = widthWindow;
	height = heightWindow;

	aspect = 16.0f / 9.0f;
	perspective = glm::perspective(glm::radians(FOV), aspect, P1, P2);
}

void Window::closeWindow()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void Window::toggleFullScreen()
{
	if (glfwGetKey(window, GLFW_KEY_F11))
	{
		Window::fullScreen = !Window::fullScreen;
		glfwDestroyWindow(window);
		if (!Window::fullScreen)

			glfwCreateWindow(width, height, Window::title.c_str(), nullptr, nullptr);
		else
		{
			const GLFWvidmode* videomod = glfwGetVideoMode(glfwGetPrimaryMonitor());
			Window::fullScreen = true;
			glfwCreateWindow(videomod->width, videomod->height, title.c_str(), glfwGetPrimaryMonitor(), nullptr);
		}
		glfwMakeContextCurrent(window);
		glfwSetWindowSizeCallback(window, windowSizeCallback);
	}
	
}
