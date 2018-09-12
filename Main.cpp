//Included libraries
#include <sfml/Graphics.hpp> //Includes graphics
#include <SFML/Audio.hpp> //Includes audio
#include <string> //Include strings
#include <cstdlib>
#include <ctime>
//End libraries

int main()
{	
	///-------------------------------------------------
	///SETUP
	///-------------------------------------------------

	//render window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", sf::Style::Titlebar | sf::Style::Close);

	//Seed our random number generation
	srand(time(NULL));

	///Sprites

	//Create a varible to hold the texture
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	//Create a sprite variable
	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	//Set the position of the sprite
	buttonSprite.setPosition(gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2, gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2);


	///Time

	//Create time variable
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTilSignal = sf::seconds(signalTimeLowerLimit);
	sf::Time timeSinceSignal = sf::seconds(0.0f);
	sf::Clock gameClock;
	

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

			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				//Check if mouse click is within boundary of button
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					float range = signalTimeUpperLimit - signalTimeLowerLimit;
					float signalSeconds = rand() % (int)range;
					timeTilSignal = sf::seconds(signalSeconds);
					//float secondsToWait = sf::Randomizer::Random(signalTimeLowerLimit, signalTimeUpperLimit);
				}
			}

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

		sf::Time frameTime = gameClock.restart();

		timeTilSignal -= frameTime;

		if (timeTilSignal.asSeconds() <= 0.0f)
		{
			buttonSprite.setColor(sf::Color::Red);
		}

		///---------------------------------------------
		///END UPDATE
		///---------------------------------------------



		///---------------------------------------------
		///DRAW
		///---------------------------------------------

		gameWindow.clear(sf::Color::Black);	

		gameWindow.draw(buttonSprite);

		gameWindow.display();

		///---------------------------------------------
		///END DRAW
		///---------------------------------------------
	}

	///-------------------------------------------------
	///END GAME LOOP
	///-------------------------------------------------

	return 0; //Letus do the time warp again
}
