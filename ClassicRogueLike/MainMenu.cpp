#include "MainMenu.hpp"



//Game* newGame();
//Game* loadGame(std::string fileName);




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

	mainTexture = loadTexture("Splash-0001.png");

	if (mainTexture == NULL)
	{
		std::cout << "Image Load Failed for Splash Screen" << std::endl;
	}

	mainFont = TTF_OpenFont("joystix monospace.otf", 32);

	if (mainFont == NULL)
	{
		std::cout << "TTF Font load failed" << std::endl;
	}

	//Draw Splash Screens
	ms = splash;

	SDL_Event e;

	Uint32 gameTicks = SDL_GetTicks();
	Uint32 gameDelta;

	Uint32 splashTime = 5000 + SDL_GetTicks(); //5 seconds


	//Need to actually detect screen size and calc based on that
	SDL_Rect* splashRect = new SDL_Rect();

	splashRect->x = 640;
	splashRect->y = 360;
	splashRect->w = 640;
	splashRect->h = 360;

	Uint8 currentAlpha = 0;

	SDL_SetTextureBlendMode(mainTexture, SDL_BLENDMODE_ADD);

	//Main Loop
	while (!quit)
	{
		//Calculate Delta
		gameDelta = SDL_GetTicks() - gameTicks;

		switch (ms)
		{
		case splash:
			if (splashTime > SDL_GetTicks())
			{
				if (currentAlpha < 254)
				{
					SDL_SetTextureAlphaMod(mainTexture, currentAlpha);
					currentAlpha += 1;
				}
			}
			else
			{
				if (currentAlpha > 0)
				{
					SDL_SetTextureAlphaMod(mainTexture, currentAlpha);
					currentAlpha -= 1;
				}
				else
				{
					ms = menu;
					mainTexture = loadTexture("MainMenu-0001.png"); //doesn't exist yet, will error out
					break;
				}
			}
			//Black Screen
			SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255);
			SDL_RenderClear(mainRenderer);
			SDL_RenderCopy(mainRenderer, mainTexture, NULL, splashRect);
			break;
		case menu:
			//Black Screen
			SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255);
			SDL_RenderClear(mainRenderer);
			break;
		}
	
			

		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_SPACE:
					std::cout << "Space my Bar" << std::endl;
					break;
				default:
					std::cout << "you pressed the any key" << std::endl;
					break;
				}
			}
		}
		SDL_RenderPresent(mainRenderer);
	}

	//Clean Everything Up
	if (!close())
	{
		std::cout << "Error shutting down: " << SDL_GetError << std::endl;
		return 1;
	}
	
	return 0;
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
		std::cout << "SDL_ttf could not initialize! Error: " << TTF_GetError() << std::endl;
		return false;
	}

	return true;
}

bool close()
{
	SDL_DestroyTexture(mainTexture);
	mainTexture = NULL;

	SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyWindow(mainWindow);
	mainWindow = NULL;
	mainRenderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return true;
}

SDL_Texture* loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image at path: " << path << "Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(mainRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			std::cout << "Could not create texture from surface. SDL_image Error: " << IMG_GetError();
		}

		//Free Surface... I'll take it!
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}