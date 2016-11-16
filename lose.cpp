
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "lose.h"
#include "menu.h"
#include <iostream>

lose::lose()
{
	l.loadFromFile("lose background.jpg");
	min.loadFromFile("minions_won.jpg");

	s.setSize(Vector2f(1000.0, 800.0));
	s.setTexture(&l);
	s.setPosition(Vector2f(0, 0));

	t.setSize(Vector2f(1000.0, 600.0));
	t.setTexture(&min);
	t.setPosition(Vector2f(0, 200.0));

	x.setSize(Vector2f(397.0, 107.0));
	x.setFillColor(sf::Color::Green);
	x.setPosition(Vector2f(340.0, 350.0));

	y.setSize(Vector2f(397.0, 107.0));
	y.setFillColor(sf::Color::Green);
	y.setPosition(Vector2f(340.0, 555.0));

	font.loadFromFile("Doctor Soos Bold 2.1.ttf");
	w.setFont(font);
	w.setString("YOU WON!!!!");
	w.setCharacterSize(150);
	w.setColor(Color(127, 199, 0, 255));
	w.setPosition(sf::Vector2f(200.0, 10.0));
}

void lose::check(RenderWindow& window, Event event, bool &replay)
{
	if (win == false) {
		if (event.type == Event::MouseButtonPressed) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (x.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
					//std::cout << "INN";
					replay = false;
					
				} else if (y.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
					window.close();
				}	
			}
		}
	}
}

void lose::changebool()
{
	win = false;
}

void lose::display(RenderWindow& window)
{
	if (win == false)
	{
		window.clear(Color::White);
		window.draw(x);
		window.draw(y);
		window.draw(s);
		std::cout << "Lost";
	} else {
		window.clear(Color::Blue);
		window.draw(t);
		window.draw(w);
		std::cout << "won";
	}
}
