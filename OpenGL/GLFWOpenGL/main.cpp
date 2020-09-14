#include <iostream>

// GLEW
#define GLEW_STATIC 
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Window dimensions 
const GLint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop 
int main()
{
	// Init GLFW 
	glfwInit();

	// Set all the required options for GLFW 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// This window hint is actually required in macOS because otherwise it will crash,
	// but there's no harm in having it on Windows as well.
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// In WindowHint, we'll set GLFW_RESIZABLE, and we'll set this to FALSE so that it prevents the window from being resized.
	// If you want it to be resized, just set it as TRUE:
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions 
	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return 1;
	}

	glfwMakeContextCurrent(window);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions 
	glewExperimental = GL_TRUE;

	// Initialize GLEW to setup the OpenGL Function pointers 
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return 1;
	}

	// Define the viewport dimensions 
	glViewport(0, 0, screenWidth, screenHeight);

	// Game loop 
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, 
		//mouse moved etc.) and call corresponding response functions 
		glfwPollEvents();

		// Render 
		// Clear the colorbuffer 
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw OpenGL 


		glfwSwapBuffers(window);
	}

	// Terminate GLFW, clearing any resources allocated by GLFW. 
	glfwTerminate();

	return 0;
}
