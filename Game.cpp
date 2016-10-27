#include "Game.h"
#include "Renderer.h"
#include "GuiManager.h"
#include "ScreenMain.h"

#undef main

Game::Game()
{
	
}

bool Game::ini()
{

	if (!Renderer::init())
		return false;

	//font color



	ScreenMain* startScreen = new ScreenMain(this);

	gui_manager.setScreen(startScreen);

	return true;

}

bool Game::run()
{
	bool running = true;

	//render loop
	while (running) //TODO: Add loop exit.
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{

			case SDL_MOUSEBUTTONUP:
				int x, y;

				SDL_GetMouseState(&x, &y);
				gui_manager.clickScreen(x, y);
				break;
			case SDL_QUIT:
				running = false;
				break;
			}
		}

		//logic here
		gui_manager.runTick();

		Renderer::iniRender();

		gui_manager.renderScreen();
		//render here

		Renderer::render();

	}

	return true;
}

bool Game::exit()
{
	Renderer::destroyRenderer();

	return true;
}


int main()
{
	Game game;
	if(!game.ini())
	{
		std::cout << "Error initializing the game" << std::endl;
	}
	if(!game.run())
	{
		std::cout << "Error running the game" << std::endl;
	}
	if(!game.exit())
	{
		std::cout << "Error exiting the game" << std::endl;
	}

	//font location / bounds

	

	


}
