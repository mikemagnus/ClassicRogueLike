#include "Game.hpp"

Game::Game(SDL_Renderer* r)
{
	gameRenderer = r;

	currentUpdate = SDL_GetTicks();

	currentDraw = SDL_GetTicks();

	quit = false;
}

void Game::update(Uint32 gameTicks)
{
	//Calculate Delta foor update
	updateDelta = gameTicks - currentUpdate;
	currentUpdate = gameTicks;

	//Detect Input

	//Feed delta into children to udate them

	//Finalize update
}

void Game::draw(Uint32 gameTicks)
{
	//Calculate Draw Delta
	drawDelta = gameTicks - currentDraw;
	currentDraw = gameTicks;
	//Default to a white window, draw on top of white
	SDL_SetRenderDrawColor(gameRenderer, 255, 255, 255, 255);
	SDL_RenderClear(gameRenderer);
	//Draw everything here



	//Call present at the end to swap buffers and present the image to screen
	SDL_RenderPresent(gameRenderer);
}

bool Game::isQuit()
{
	return Game::quit;
}