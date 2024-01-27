#ifndef GAME_H

#define GAME_H
#include <iostream>
#include <SDL.h>
#include <SDL_keycode.h>
#include <SDL_ttf.h>

typedef Uint32 deltaTime;	//A representation of a change in time
typedef Uint32 time;		//A specific point in time

class Game
{
public:
	//initialize a new game
	Game();
	//load a game from file (destroys the file, no save scumming)
	Game(std::string& const fileName);
private:
	//Initialize Game and Libraries
	bool init();

	//load game state from file
	bool load(std::string& const filename);

	//Called Once Per Frame
	//THE ONLY UPDATE THAT DOES NOT TAKE DELTA TIME. It calculates delta time and passes it to the children.
	//Every other update will take deltaTime as a parameter.
	void update();

	//Called Once Per Frame. Calls Draw on all nodes that are on screen
	void draw(deltaTime dt);

	//References to the main gameWindow and gameRenderer. 
	//All drawing will be done through the draw(deltaTime dt) 
	//method and will only draw to this renderer and window
	SDL_Window* gameWindow;
	SDL_Renderer* gameRenderer;


	//All in Milliseconds
	time lastFrame;		//Last frame started in ms
	time currentFrame;	//This frame started in ms
	deltaTime primaryDelta;		//Delta Time since last update
};

#endif