#include <iostream>
#include <SDL.h>
#include <SDL_keycode.h>

//References to the SDL2 Objects for the window and Renderer
SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;

bool init();
bool load();

bool initialized;
bool quit;
bool loaded;

int main(int argc, char** args)
{
	quit = false;

	if (argc > 1)
	{
		//Handle Potential Arguments
	}

	if (!init())
	{
		std::cout << "Error Initializing" << SDL_GetError() << std::endl;
	}

	initialized = true;

	if (!load())
	{
		std::cout << "Error Loading Assets" << SDL_GetError() << std::endl;
	}

}