#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;

sf::Texture text;
sf::Sprite spr;

float pX = 400;
float pY = 800;
float speed = 5;
				//      X   Y
Vector2f originLoc = { 400,800 };

Vector2f upLoc = {400, 650};
Vector2f downLoc = {400, 950};
Vector2f leftLoc = {250,800};
Vector2f rightLoc = {550, 800};


Player::Player()
{
	text.loadFromFile("ship.png");
	spr.setTexture(text);
	spr.setScale(1.5,1.5);
	spr.setOrigin(50,25);
}
Sprite Player::getSprite()
{
	return spr;
}
void Player::checkAction()
{
	if (sf::Keyboard::isKeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			moveTo(leftLoc.x, leftLoc.y);
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			moveTo(rightLoc.x, rightLoc.y);
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			moveTo(upLoc.x, upLoc.y);
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			moveTo(downLoc.x, downLoc.y);
			
		}
		else {
			moveTo(originLoc.x, originLoc.y);
			
		}
	}
	spr.setPosition(pX, pY);
}
void Player::moveTo(float x,float y)
{
	if (x > pX)
	{
		pX += speed;
	}
	else if (x < pX)
	{
		pX -= speed;
	}

	if (y > pY)
	{
		pY += speed;
	}
	else if (y < pY)
	{
		pY -= speed;
	}
}
float Player::getX()
{
	return pX;
}
float Player::getY()
{
	return pY;
}