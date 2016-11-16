#pragma once
//
//  lose.h
//  Frogger Game
//
//  Created by Yasser on 12/9/15.
//  Copyright © 2015 Yasser. All rights reserved.
//

#ifndef lose_h
#define lose_h
using namespace sf;
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class lose
{
private:
	Texture l, min;
	sf::RectangleShape s, x, y, t;
	bool gameEnter;
	bool win = true;
	Font font;
	Text w;

public:
	lose();
	void display(RenderWindow&);
	void check(RenderWindow&, Event, bool&);
	void changebool();
};


#endif /* lose_h */
