#ifndef MAIN_MENU_H

#define MAIN_MENU_H

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
	msUninitialized = 0,
	msMain = 1,
	msMenu = 2,
	msNewGame = 3,
	msLoadGame = 4,
	msOptions = 5
};

enum MainMenuCursor
{
	mmhidden = 0,
	mmLoadGame = 1,
	mmNewGame = 2,
	mmOptions = 3,
	mmQuit = 4
};

//References to the SDL2 Objects for the window and Renderer
SDL_Window* mainWindow;
SDL_Renderer* mainRenderer;
SDL_Texture* mainTexture;

TTF_Font* mainFont;

//Game Object
Game* game;
//Menu State enum
MenuState ms;
//menu state will set to quit 
bool quit;

//Close SDL
bool close();
#endif