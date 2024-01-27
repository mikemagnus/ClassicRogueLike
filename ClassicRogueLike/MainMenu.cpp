#include <iostream>
#include <SDL.h>
#include <SDL_keycode.h>
#include <SDL_ttf.h>


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
		return 1;
	}

	initialized = true;

	if (!load())
	{
		std::cout << "Error Loading Assets" << SDL_GetError() << std::endl;
		return 1;
	}

	loaded = true;

	while (!quit)
	{
		SDL_GetTicks();
	}
}

bool init()
{
	// Initialize SDL. SDL_Init will return -1 if it fails.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{
		return false;
	}

	// Create our window
	mainWindow = SDL_CreateWindow("ClassicRogueLike", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);

	// Make sure creating the window succeeded
	if (!mainWindow) 
	{
		return false;
	}

	mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!mainRenderer)
	{
		return false;
	}

	//White Window
	SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);

	//Set the whole window to white
	SDL_RenderClear(mainRenderer);

	//Flip the buffers
	SDL_RenderPresent(mainRenderer);

	return true;
}

bool load()
{
	//todo: actually load stuff
	return true;
}