//Included libraries
#include <sfml/Graphics.hpp> //Includes graphics
#include <SFML/Audio.hpp> //Includes audio
#include <string> //Include strings
//End libraries

int main()
{	
	///-------------------------------------------------
	///SETUP
	///-------------------------------------------------

	//render window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", sf::Style::Titlebar | sf::Style::Close);

	///-------------------------------------------------
	///END SETUP
	///-------------------------------------------------

	///-------------------------------------------------
	///Game Loop
	///-------------------------------------------------

	while (gameWindow.isOpen())
	{
		///---------------------------------------------
		///INPUT
		///---------------------------------------------

		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			//Process Events

			//Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				//Close the game window
				gameWindow.close();
			}//End Closed event
		}//End input polling while loop

		///---------------------------------------------
		///END INPUT
		///---------------------------------------------

		///---------------------------------------------
		///UPDATE
		///---------------------------------------------


		///---------------------------------------------
		///END UPDATE
		///---------------------------------------------

		///---------------------------------------------
		///DRAW
		///---------------------------------------------
		gameWindow.clear();
		gameWindow.display();
	}

	///-------------------------------------------------
	///END GAME LOOP
	///-------------------------------------------------

	return 0; //Letus do the time warp again
}
