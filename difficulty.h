#pragma once
#ifndef Difficulty_H
#define Difficulty_H

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "levels.h"
using namespace sf;

class difficulity
{
private:
	RectangleShape background;
	Sprite easy;
	Sprite medium;
	Sprite hard;
	Text easyy;
	Text mediumm;
	Text hardd;
	Text choose;
	Texture t;
	Font font;
	Texture diff;
	bool choice = false;

	levels o;

public:
	difficulity();
	void initialize();
	void display(RenderWindow&);
	void check(RenderWindow&, Event&, bool&, int&);

};

#endif /* difficulity_h */
