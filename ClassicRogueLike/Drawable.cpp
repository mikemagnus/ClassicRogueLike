#include "Drawable.hpp"

SDL_Texture* Drawable::loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image at path: " << path << "Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(r, loadedSurface);
		if (newTexture == NULL)
		{
			std::cout << "Could not create texture from surface. SDL_image Error: " << IMG_GetError();
		}

		//Free Surface... I'll take it!
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}