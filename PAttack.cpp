#include "PAttack.h"
#include <SFML\Graphics.hpp>
using namespace sf;

float PAttack::xpos;
float PAttack::ypos;
sf::Sprite PAttack::attack;
sf::Texture PAttack::bullet;
float velocity = 4;

PAttack::PAttack(float h, float q) //MAKE TEXTURES LOAD AT START
{
	PAttack::xpos = 100;
	PAttack::ypos = 500;
	bullet.loadFromFile("attack.png");
	PAttack::attack.setTexture(bullet);
}
void PAttack::update()
{
	//xPos -= velocity;
	ypos -= velocity;
	attack.setPosition(PAttack::xpos, PAttack::ypos);
}
float PAttack::getX()
{
	return PAttack::xpos;
}
float PAttack::getY()
{
	return PAttack::ypos;
}
Sprite PAttack::getSprite()
{
	return PAttack::attack;
}
