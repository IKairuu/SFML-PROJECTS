#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class sprite
{
	private: 
	//Variables
	sf::RenderWindow* window ;
	sf::VideoMode video ;
	sf::Event even ;
	sf::Texture backgroundTexture ;
	sf::Texture characterTexture ;
	sf::RectangleShape character ;
	sf::RectangleShape background ;
	sf::Vector2f position ;
	sf::Vector2u textureSize ;
	sf::IntRect characterRect = {0, 160, 128, 174} ;
	sf::IntRect backgroundRect = {60,0,180,130} ;
	int characterFrames = 8 ;
	bool right = true ;
	//Funtions
	void initWindow();
	void initVariables();
	void initCharacter() ;
	void initBackground();
	public:
		sprite();//Constructor
		~sprite();//Destructor
		const bool windowOpen() const ;
		void characterMoveLeft() ;
		void characterMoveRight() ;
		void updateEvents() ;
		void characterNotMoving() ;
		void updateProgram() ;
		void renderProgram() ;
};

#endif

