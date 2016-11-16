#pragma once
//
//  menu.h
//  Menu Class
//
//  Created by Yasser on 12/7/15.
//  Copyright © 2015 Yasser. All rights reserved.
//

#ifndef Menu_h
#define Menu_h

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "difficulty.h"
using namespace sf;

class Menu
{
private:
	Sprite logo;
	RectangleShape background;
	Sprite head;
	Sprite heads;
	Text newg;
	Text sett;
	Texture t;
	Texture n;
	Texture l;
	Font font;
	difficulity x;
	bool hasDifficulty = false;
public:
	Menu();
	void check(RenderWindow&, Event&, bool&, int&);
	void display(RenderWindow&, Event&);

};

#endif /* menu_h */
