#pragma once
#include <SFML\Graphics.hpp>

class AnimatedSprite
{
public:
	AnimatedSprite(sf::Sprite spr);
	AnimatedSprite(sf::Sprite spr, sf::Sprite spr2);
	AnimatedSprite(sf::Sprite spr, sf::Sprite spr2, sf::Sprite spr3);
	AnimatedSprite(sf::Sprite spr, sf::Sprite spr2, sf::Sprite spr3, sf::Sprite spr4);
	void nextFrame(int del);
	sf::Sprite getSpr();
	void setLocation(int x, int y);
};