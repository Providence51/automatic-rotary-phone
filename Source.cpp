#include <SFML/Graphics.hpp>
#include "Player.h"
#include "AnimatedSprite.h"
#include "PAttack.h"
#include <vector>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 1000), "");
	window.setFramerateLimit(60);
	Player mainNig;
	
	std::vector<PAttack> attackVec;
	std::vector<PAttack>::iterator proIter;

	int attackTime = 30;
	

    while (window.isOpen())
    {
		window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
				return 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (attackTime >= 60)
				{
					//attackVec.push_back(newAtt);
					attackVec.emplace_back(PAttack(mainNig.getX() - 20, mainNig.getY() - 25));
					attackTime = 0;
				}
			}
        }
        
		std::cout << attackVec.size() << std::endl;
		mainNig.checkAction();
		window.draw(mainNig.getSprite());

		for (int x = 0; x < attackVec.size(); x++)
		{
			attackVec[x].update();
			std::cout << "Y " << x << ": "<<attackVec[x].getY() << std::endl;
			if (attackVec[x].getY() < 0)
			{
				attackVec.erase(attackVec.begin() + x);
			}
			else
			{
				window.draw(attackVec[x].getSprite());
			}
			
		}
		/*for (proIter = attackVec.begin(); proIter != attackVec.end(); proIter++)
		{
			proIter->update();
			if (proIter->getY() < 0)
			{
				attackVec.erase(proIter);
			}
			else
				window.draw(proIter->getSprite());
		}*/
        window.display();
		attackTime++;
    }

    return 0;
}
