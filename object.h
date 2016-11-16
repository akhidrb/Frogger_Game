#pragma once
#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
class object
{
public:
	enum direction { right, left };
	enum stuff { dog, redCar, blueCar, logs, turtles, buses };
	object();
	void editObj(stuff, int);
	bool outOfBounds();
	sf::Vector2f abspos(bool);
	void move(direction, sf::Time, int);
	sf::FloatRect boundingBox();
	void displayObj(sf::RenderWindow&);
private:
	sf::Sprite objsprite;
	sf::Texture redText, blueText, dogText, logText, turtText, busText;
	sf::IntRect crocRect, logRect, turtRect, busRect;

};
#endif
//#include "object.cpp"