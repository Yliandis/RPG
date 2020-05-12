#include "Game.h"

#include <iostream>

int main()
{
	Game game;
	
	try
	{
		game.run();
	}
	catch (std::runtime_error& err)
	{
		std::cerr << err.what() << std::endl;
		return 1;
	}
	
	return 0;
}
