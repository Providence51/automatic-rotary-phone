#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Player
{
public:
	Player();
	Sprite getSprite();
	void checkAction();
	float getX();
	float getY();
	void moveTo(float x, float y);
};