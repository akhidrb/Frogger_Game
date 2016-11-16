//
//  difficulity.cpp
//  Frogger Game
//
//  Created by Yasser on 12/8/15.
//  Copyright © 2015 Yasser. All rights reserved.
//

#include <stdio.h>
#include "difficulty.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
using namespace sf;

difficulity::difficulity()
{
}

void difficulity::display(RenderWindow& window)
{

	switch (choice)
	{
	case true:
	{
		o.display(window);
		break;
	}
	case false:
		window.draw(background);
		window.draw(easy);
		window.draw(medium);
		window.draw(hard);
		window.draw(easyy);
		window.draw(mediumm);
		window.draw(hardd);
		window.draw(choose);
		break;
	}

}

void difficulity::check(RenderWindow& window, Event& event, bool &gameEnter, int &levDif)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (easy.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				o.easylevel();
				choice = true;
				gameEnter = true;
				levDif = 0;
			}
			else if (medium.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				o.mediumlevel();
				choice = true;
				gameEnter = true;
				levDif = 1;

			}
			else if (hard.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				o.hardlevel();
				choice = true;
				gameEnter = true;
				levDif = 2;
			}
		}
	}
}

void difficulity::initialize()
{
	diff.loadFromFile("diff.png");

	t.loadFromFile("IcATAG6.jpg");
	t.setSmooth(true);

	font.loadFromFile("Doctor Soos Bold 2.1.ttf");

	background.setSize(Vector2f(1000.0, 800.0));
	background.setTexture(&t);
	background.setPosition(Vector2f(0.0, 0.0));

	easy.setTexture(diff);
	easy.setPosition(Vector2f(170, 400));
	easy.scale(sf::Vector2f(0.6f, 0.5f));

	medium.setTexture(diff);
	medium.setPosition(Vector2f(170, 500));
	medium.scale(sf::Vector2f(0.6f, 0.5f));

	hard.setTexture(diff);
	hard.setPosition(Vector2f(170, 600));
	hard.scale(sf::Vector2f(0.6f, 0.5f));

	easyy.setFont(font);
	easyy.setString("Easy");
	easyy.setCharacterSize(80);
	easyy.setColor(Color(127, 199, 0, 255));
	easyy.setPosition(sf::Vector2f(230, 370));

	mediumm.setFont(font);
	mediumm.setString("Medium");
	mediumm.setCharacterSize(80);
	mediumm.setColor(Color(127, 199, 0, 255));
	mediumm.setPosition(sf::Vector2f(200, 476));

	hardd.setFont(font);
	hardd.setString("Hard");
	hardd.setCharacterSize(83);
	hardd.setColor(Color(127, 199, 0, 255));
	hardd.setPosition(sf::Vector2f(235, 573));

	choose.setFont(font);
	choose.setString("Choose a Difficulty!!!");
	choose.setCharacterSize(55);
	choose.setColor(Color(11, 43, 141, 255));
	choose.setPosition(sf::Vector2f(135, 290));

}
