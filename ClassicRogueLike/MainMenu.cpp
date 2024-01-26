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

	loaded = true;

	while (!quit)
	{

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
	mainWindow = SDL_CreateWindow("ClassicRogueLike", 0, 0, 1920, 1080, SDL_WINDOW_SHOWN);

	// Make sure creating the window succeeded
	if (!mainWindow) 
	{
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return false;
	}

	mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);

	//White Window
	SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);

	//Set the whole window to white
	SDL_RenderClear(mainRenderer);

	//Flip the buffers
	SDL_RenderPresent(mainRenderer);

	return true;
}