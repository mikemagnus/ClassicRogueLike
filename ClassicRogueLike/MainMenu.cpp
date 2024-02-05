//Standard Libraries
#include <iostream>

//SDL Libraries
#include <SDL.h>
#include <SDL_keycode.h>
#include <SDL_image.h>	//For Loading PNG's for game assets
#include <SDL_ttf.h>	//True Type for text rendering

//Internal Headers
#include "Game.hpp"

//Enum for menu state
enum MenuState
{
	uninitialized = 0,
	splash = 1,
	menu = 2,
	newGame = 3,
	loadGame = 4,
	options = 5,
	quit = 6
};

//References to the SDL2 Objects for the window and Renderer
SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
SDL_Texture* mainTexture;

//Game Object
Game* game;
//Menu State enum
MenuState ms;
//application is quitting if true
bool quit;

//Initialize SDL
bool init();

SDL_Texture* loadTexture(std::string path);

//Close SDL
bool close();

Game* newGame();
Game* loadGame(std::string fileName);




int main(int argc, char** args)
{
	quit = false;
	ms = uninitialized;

	if (argc > 1)
	{
		//Handle Potential Arguments
	}

	if (!init())
	{
		std::cout << "Error Initializing" << SDL_GetError() << std::endl;
		return 1;
	}

	//Draw Splash Screens
	ms = splash;

	//Black Screen
	SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255);
	SDL_RenderClear(mainRenderer);
	SDL_RenderPresent(mainRenderer);

	//Main Menu Loop
	while (!quit)
	{
		//Draw main menu
		//Handle input
	}

	//Clean Everything Up
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

	return true;
}

SDL_Texture* loadTexture(std::string path)
{

}