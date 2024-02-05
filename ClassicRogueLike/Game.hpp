#ifndef GAME_H

#define GAME_H

//Standard Libraries
#include <iostream>

//SDL Libraries
#include <SDL.h>

//Game Headers

class Game
{
private:
	//A reference to the renderer fed into the constructor
	SDL_Renderer* gameRenderer;

	// All in Milliseconds 
	// todo: patch if someone runs the game for more than 24 days straight
	Uint32 currentUpdate;	//This frame started in ms
	Uint32 updateDelta;	//Delta Time since last update

	Uint32 currentDraw;
	Uint32 drawDelta;

	//Game State Variables
	bool quit;

public:
	//initialize a new game object
	Game(SDL_Renderer* r);
	void update(Uint32 gameTicks);
	void draw(Uint32 gameTicks);
	bool isQuit();
};

#endif