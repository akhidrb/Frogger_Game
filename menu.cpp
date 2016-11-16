//
//  menu.cpp
//  Menu Class
//
//  Created by Yasser on 12/7/15.
//  Copyright © 2015 Yasser. All rights reserved.
//

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "difficulty.h"
#include <iostream>

Menu::Menu()
{
	t.loadFromFile("IcATAG6.jpg");
	t.setSmooth(true);


	n.loadFromFile("frogger.png");

	background.setSize(Vector2f(1000.0, 800.0));
	background.setTexture(&t);
	background.setPosition(Vector2f(0.0, 0.0));

	logo.setTexture(n);
	logo.setPosition(sf::Vector2f(130, 215));
	logo.scale(sf::Vector2f(1.f, 1.f));

	l.loadFromFile("words.png");

	heads.setTexture(l);
	heads.setPosition(Vector2f(150, 310));
	heads.scale(sf::Vector2f(0.39f, 0.37f));



	head.setTexture(l);
	head.rotate(180);
	head.setPosition(Vector2f(480, 710));
	head.scale(sf::Vector2f(0.39f, 0.37f));


	font.loadFromFile("Doctor Soos Bold 2.1.ttf");


	newg.setFont(font);
	newg.setString("New Game");
	newg.setCharacterSize(80);
	newg.setColor(Color(127, 199, 0, 255));
	newg.setPosition(sf::Vector2f(170, 360));

	sett.setFont(font);
	sett.setString("Settings");
	sett.setCharacterSize(85);
	sett.setColor(Color(127, 199, 0, 255));
	sett.setPosition(sf::Vector2f(185, 525));


}


void Menu::check(RenderWindow& window, Event& event, bool &gameEnter, int &levDif)
{
	if (hasDifficulty) x.check(window, event, gameEnter, levDif);
	if (event.type == Event::MouseButtonPressed)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (heads.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				x.initialize();
				hasDifficulty = true;
			}
		}
	}
}


void Menu::display(RenderWindow& window, Event& event)
{
	if (hasDifficulty == false) {
		window.draw(background);
		window.draw(heads);
		window.draw(head);
		window.draw(logo);
		window.draw(newg);
		window.draw(sett);
	} else x.display(window);

}

