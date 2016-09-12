#include "AnimatedSprite.h"
#include <array>
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace sf;

Sprite spr1;
Sprite spr2;
Sprite spr3;
Sprite spr4;
int index = 0;
int frameAmount = 0;
int reduction = 0;
int drawD = 0;

Sprite sprMain = spr1;

AnimatedSprite::AnimatedSprite(sf::Sprite spr5)
{
	spr1 = spr5;
	frameAmount = 1;
	reduction = 4;
}
AnimatedSprite::AnimatedSprite(sf::Sprite spr5, Sprite spr6)
{
	spr1 = spr5;
	spr2 = spr6;
	frameAmount = 2;
	reduction = 3;
}
AnimatedSprite::AnimatedSprite(sf::Sprite spr5, Sprite spr6, Sprite spr7)
{
	spr1 = spr5;
	spr2 = spr6;
	spr3 = spr7;
	frameAmount = 3;
	reduction = 2;
}
AnimatedSprite::AnimatedSprite(sf::Sprite spr5, Sprite spr6, Sprite spr7, Sprite spr8)
{
	spr1 = spr5;
	spr2 = spr6;
	spr3 = spr7;
	spr4 = spr8;
	frameAmount = 4;
	reduction = 1;
}

void AnimatedSprite::nextFrame(int delay)
{
	if (drawD == delay)
	{
		Sprite pickle[4];
		Sprite newSpr;

		if (frameAmount >= 1)  // REPLACE THIS WITH WHILE LOOP
			pickle[0] = spr1;  //
		if (frameAmount >= 2)  //
			pickle[1] = spr2;  //
		if (frameAmount >= 3)  //
			pickle[2] = spr3;  //
		if (frameAmount == 4)  //
			pickle[3] = spr4;  //

		if (index == (std::extent<decltype(pickle)>::value - reduction))
			index = 0;
		else
			index++;
		newSpr = pickle[index];
		sprMain = newSpr;
		drawD = 0;
	}
	else
		drawD++;
}
Sprite AnimatedSprite::getSpr()
{
	return sprMain;
}
void AnimatedSprite::setLocation(int x, int y)
{
	sprMain.setPosition(x, y);
}