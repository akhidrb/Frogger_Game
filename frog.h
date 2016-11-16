#pragma once
#ifndef FROG_H
#define FROG_H
#include <SFML/Graphics.hpp>
#include "object.h"

class frog
{
	
public:
	enum direction { up, down, right, left };
	frog();
	void move(direction, float);
	void animFrog();
	bool collision(object, bool);
	sf::Vector2f getPos();
	void setPos();
	void frog::display(sf::RenderWindow&);
	
private:
	sf::Sprite sprite;
	sf::Texture t;
	sf::IntRect rectText;
	//float pixels = 50.0;
};
#endif
//#include "object.cpp"