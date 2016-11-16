#include"frog.h"
#include <SFML/Graphics.hpp>
#include "object.h"
//#define pixels 50.0

frog::frog() {
	t.loadFromFile("frog_sprite.png");
	rectText.left = 0; rectText.top = 0; rectText.width = 130; rectText.height = 240;
	sprite.setScale(0.4f, 0.4f);
	sprite.setPosition(sf::Vector2f(430.0, 850.0));
	//sprite.setPosition(sf::Vector2f(430.0, 340.0));
	sprite.setTexture(t, false);
	sprite.setTextureRect(rectText);
	sprite.setOrigin(sf::Vector2f(65.0, 240.0));
}
bool frog::collision(object x, bool water)
{
	sf::Vector2f p = x.abspos(water);
	sf::FloatRect f = sprite.getGlobalBounds();
	if (f.contains(p)) return true;
	else return false;
}
sf::Vector2f frog::getPos()
{
	sf::Vector2f pos = sprite.getPosition();
	return pos;
}
void frog::setPos()
{
	sprite.setPosition(sf::Vector2f(430.0, 850.0));
}
void frog::move(direction n, float speed) {
	switch (n) {
	case up:
		//sprite.setRotation(0);
		sprite.move(sf::Vector2f(0, -speed));
		rectText.left = 130;
		break;
	case down:
		sprite.move(sf::Vector2f(0, speed));
		//sprite.setRotation(180);
		rectText.left = 130;
		break;
	case right:
		sprite.move(sf::Vector2f(speed, 0));
		//sprite.setRotation(90);
		rectText.left = 130;
		break;
	case left:
		//sprite.setRotation(270);
		sprite.move(sf::Vector2f(-speed, 0));
		rectText.left = 130;
		break;
	}
	sprite.setTextureRect(rectText);
}

void frog::animFrog() {
	if (rectText.left == 130) rectText.left = 0;
	sprite.setTextureRect(rectText);
}

void frog::display(sf::RenderWindow &window)
{
	window.draw(sprite);
}