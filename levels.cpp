//
//  levels.cpp
//  Frogger Game
//
//  Created by Yasser on 12/8/15.
//  Copyright © 2015 Yasser. All rights reserved.
//

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "levels.h"
using namespace sf;

levels::levels()
{}

void levels::easylevel()
{
	eas.loadFromFile("easy level.jpg");
	a.setSize(Vector2f(1000.0, 800.0));
	a.setTexture(&eas);
	a.setPosition(Vector2f(0, 0));
	iseasy = true;
}

void levels::mediumlevel()
{
	med.loadFromFile("medium level1.jpg");
	b.setSize(Vector2f(1000.0, 800.0));
	b.setTexture(&med);
	b.setPosition(Vector2f(0.0, 0.0));
	ismedium = true;
}


void levels::hardlevel()
{
	har.loadFromFile("hard level1.jpg");

	c.setSize(Vector2f(1000.0, 800.0));
	c.setTexture(&har);
	c.setPosition(Vector2f(0.0, 0.0));
	ishard = true;

}

void levels::display(RenderWindow& window)
{
	if (iseasy == true)
	{
		window.draw(a);
	}
	else if (ismedium == true)
	{
		window.draw(b);
	}
	else if (ishard == true)
	{
		window.draw(c);
	}
}

