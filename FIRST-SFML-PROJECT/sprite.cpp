#include "sprite.h"

void sprite::initWindow()
{
	this->video.width = 800 ;
	this->video.height = 600 ; 
	this->window = new sf::RenderWindow(this->video, "SPRITE", sf::Style::Close | sf::Style::Resize) ;
	this->window->setFramerateLimit(60) ;
}
void sprite::initVariables()
{
	this->window = nullptr ;
	this->characterTexture.loadFromFile("C:\\Users\\asus\\Documents\\StudySFML\\Animation2\\human.png") ;
	this->backgroundTexture.loadFromFile("C:\\Users\\asus\\Documents\\StudySFML\\Animation2\\city.png") ;
	this->background.setTextureRect(this->backgroundRect) ;
	this->character.setTextureRect(this->characterRect) ;
	this->textureSize = this->characterTexture.getSize() ;
	this->textureSize.x /= this->characterFrames ;
	this->textureSize.y /= 3 ;
}
void sprite::initCharacter()
{
	this->character.setTexture(&this->characterTexture) ;
	this->character.setPosition(400.0f,455.0f) ;
	this->character.setSize(sf::Vector2f(120.0f,160.0f));
}
void sprite::initBackground()
{
	this->background.setTexture(&this->backgroundTexture) ;
	this->background.setSize(sf::Vector2f(800.0f,600.0f));
}
const bool sprite::windowOpen() const 
{
	return this->window->isOpen() ;
}
sprite::sprite()
{
	this->initVariables() ;
	this->initWindow() ;
	this->initCharacter() ;
	this->initBackground() ;
}

sprite::~sprite()
{
	delete this->window ;
}

void sprite::characterMoveLeft()
{
	if(this->right)
	{
		this->character.setScale(-1.0f,1.0f) ;
		this->position = this->character.getPosition() ;
		this->character.setPosition(this->position.x+100,this->position.y) ;
	}
	this->characterRect.top = 165 ;
	this->right = false ;
	if(this->backgroundRect.left <= 270 && this->backgroundRect.left >= 10)
	{
		this->backgroundRect.left-- ;	
	}
	else
	{
		this->character.move(-5.0f,0.0f) ;
		if(this->backgroundRect.left > 270)
		{
			if(this->character.getPosition().x <= 400.0f)
			{
				this->backgroundRect.left = 270 ;
				this->character.setPosition(400.0f,455.0f) ;
			}
		}
	}
	
	if(this->characterFrames >= 7)
	{
		this->characterFrames = 1 ;
		this->characterRect.left = 128 ;
	}
	else
	{
		this->characterRect.left += 128 ;
		this->characterFrames++ ;
	}
}
void sprite::characterMoveRight()
{
	if(!this->right)
	{
		this->character.setScale(1.0f,1.0f) ;
		this->position = this->character.getPosition() ;
		this->character.setPosition(this->position.x-100,this->position.y) ;
	}
	this->characterRect.top = 165 ;
	this->right = true ;
	if(this->backgroundRect.left <= 270 && this->backgroundRect.left >= 10)
	{
		this->backgroundRect.left++ ;
	}
	else
	{
		this->character.move(5.0f,0.0f) ;
		if(this->backgroundRect.left < 10)
		{
			if(this->character.getPosition().x >= 400.0f)
			{
				this->backgroundRect.left = 10 ;
				this->character.setPosition(400.0f,455.0f) ;
			}
		}
	}
	
	if(this->characterFrames >= 7)
	{
		this->characterFrames = 1 ;
		this->characterRect.left = 128 ;
	}
	else
	{
		this->characterRect.left += 128 ;
		this->characterFrames++ ;
	}
}
void sprite::updateEvents()
{
	while(this->window->pollEvent(this->even))
	{
		switch(this->even.type)
		{
			case sf::Event::Closed:
				this->window->close() ;
				break ;
			case sf::Event::KeyPressed:
				{
					if(this->even.key.code == sf::Keyboard::A)
					{
						this->characterMoveLeft() ;	
					}
					else if(this->even.key.code == sf::Keyboard::D)
					{
						this->characterMoveRight() ;
					}
					else if(this->even.key.code == sf::Keyboard::Escape)
					{
						this->window->close() ;
					}
				}
				break ;
			case sf::Event::KeyReleased:
				this->characterNotMoving() ;
				break ;
		}
	}
	this->background.setTextureRect(this->backgroundRect) ;
	this->character.setTextureRect(this->characterRect) ;
}
void sprite::characterNotMoving()
{
	this->characterRect.left = 384 ;
	this->characterRect.top = 330 ;
}
void sprite::updateProgram()
{
	this->updateEvents() ;
}
void sprite::renderProgram()
{
	this->window->clear() ;
	this->window->draw(this->background) ;
	this->window->draw(this->character) ;
	this->window->display() ;
}
