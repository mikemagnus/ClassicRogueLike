//Standard Libraries
#include <iostream>

//SDL Libraries
#include <SDL.h>
#include <SDL_keycode.h>
#include <SDL_image.h>	//For Loading PNG's for game assets
#include <SDL_ttf.h>	//True Type for text rendering


//References to the SDL2 Objects for the window and Renderer
SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
SDL_Texture* splashTexture;

bool quit;

bool init();
bool close();
SDL_Texture* loadTexture(std::string path);

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

	splashTexture = loadTexture("Splash-0001.png");

	if (splashTexture == NULL)
	{
		std::cout << "Image Load Failed for Splash Screen" << std::endl;
	}

	Uint32 gameTicks = SDL_GetTicks();
	Uint32 gameDelta;

	Uint32 splashTime = 5000 + SDL_GetTicks(); //5 seconds
}

bool init()
{
	// Initialize SDL. SDL_Init will return -1 if it fails.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	// Create our window
	mainWindow = SDL_CreateWindow("ClassicRogueLike", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);

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

	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cout << "SDL_image could not initialize! Error: " << IMG_GetError() << std::endl;
		return false;
	}

	if (TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not inititalize! Error: " << TTF_GetError() << std::endl;
		return false;
	}

	return true;
}