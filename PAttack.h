#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class PAttack
{
public:
	PAttack(float x, float y);
	float getX();
	float getY();
	void update();
	Sprite getSprite();
private:
	static float xpos;
	static float ypos;
	static sf::Sprite attack;
	static sf::Texture bullet;
	float velocity = 4;
};