#pragma once
#ifndef levels_h
#define levels_h
using namespace sf;
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class levels
{
private:
	Texture eas;
	Texture med;
	Texture har;
	RectangleShape a;
	RectangleShape b;
	RectangleShape c;
	bool iseasy = false;
	bool ismedium = false;
	bool ishard = false;

public:
	levels();
	void easylevel();
	void mediumlevel();
	void hardlevel();
	void display(RenderWindow&);
};

#endif /* levels_h */
