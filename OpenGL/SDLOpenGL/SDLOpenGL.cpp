#include <iostream>

// GLEW
#define GLEW_STATIC 
#include <GL/glew.h>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

// Window dimensions 
const GLint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop 
int main(int argc, char *argv[])
{
	// Init SDL 
	SDL_Init(SDL_INIT_EVERYTHING);

	// OpenGL Profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// OpenGL Version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); 
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3); 
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	// Window
	SDL_Window* window = SDL_CreateWindow("OpenGL", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointersand extensions
	glewExperimental = GL_TRUE;

	// Initialize GLEW to setup the OpenGL Function pointers 
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Define the viewport dimensions 
	glViewport(0, 0, WIDTH, HEIGHT);

	SDL_Event windowEvent;

	while (true)
	{
		if (SDL_PollEvent(&windowEvent))
		{
			if (windowEvent.type == SDL_QUIT) break;
		}

		// Clear the colorbuffer 
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw OpenGL 

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
