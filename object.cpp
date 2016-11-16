#include"object.h"
#include <SFML/Graphics.hpp>
#define pixels 50
object::object()
{
	dogText.loadFromFile("dog.png");
	//rectText.left = 0; rectText.top = 0; rectText.width = 130; rectText.height = 240;
	objsprite.setScale(0.4f, 0.4f);
	objsprite.setPosition(sf::Vector2f(20.0, 20.0));
	objsprite.setTexture(dogText, false);
	objsprite.setTextureRect(sf::IntRect(0, 0, 100, 200));
}

void object::editObj(stuff th, int p) {
	float x = -180.0, xLeft = 1100.0; 
	int t = rand() % 4;
	float f;
	/* 
	switch (t) {
	case 0:
		f = 40.0;
		break;
	case 1:
		f = 100.0;
		break;
	case 2:
		f = 180.0;
		break;
	case 3:
		f = 240.0;
		break;
	}
	*/
	float yCar; 
	switch (p) {
	case 0:
		yCar = 425.0;
		break;
	case 1:
		yCar = 545.0;
		break;
	case 2:
		yCar = 645.0;
		break;
	case 3:
		yCar = 320.0;
		break;
	}
	switch (th) {
	case redCar:
		redText.loadFromFile("car_red.png");
		//rectText.left = 0; rectText.top = 0; rectText.width = 130; rectText.height = 240;
		objsprite.setScale(0.7f, 0.7f);
		objsprite.setPosition(sf::Vector2f(xLeft, yCar));
		objsprite.setTexture(redText, false);
		objsprite.setTextureRect(sf::IntRect(0, 0, 300, 200));
		break;	
	case dog:
		dogText.loadFromFile("dog.png");
		//rectText.left = 0; rectText.top = 0; rectText.width = 130; rectText.height = 240;
		objsprite.setScale(0.7f, 0.7f);
		objsprite.setPosition(sf::Vector2f(x, yCar));
		objsprite.setTexture(dogText, false);
		objsprite.setTextureRect(sf::IntRect(0, 0, 300, 200));
		break;
	case blueCar:
		blueText.loadFromFile("car_blue.png");
		//rectText.left = 0; rectText.top = 0; rectText.width = 130; rectText.height = 240;
		objsprite.setScale(0.6f, 0.6f);
		objsprite.setPosition(sf::Vector2f(xLeft, yCar));
		objsprite.setTexture(blueText, false);
		objsprite.setTextureRect(sf::IntRect(0, 0, 300, 200));
		break;
	case buses:
		busText.loadFromFile("bus2.png");
		//rectText.left = 0; rectText.top = 0; rectText.width = 130; rectText.height = 240;
		objsprite.setScale(0.8f, 0.8f);
		objsprite.setPosition(sf::Vector2f(x, yCar));
		objsprite.setTexture(busText, false);
		objsprite.setTextureRect(sf::IntRect(0, 0, 200, 100));
		break;
	case logs:
		logText.loadFromFile("log1.png");
		//rectText.left = 0; rectText.top = 0; rectText.width = 130; rectText.height = 240;
		objsprite.setScale(0.5f, 0.5f);
		if (p == 0) objsprite.setPosition(sf::Vector2f(x, 45.0));
		else objsprite.setPosition(sf::Vector2f(x, 190.0));
		objsprite.setTexture(logText, false);
		objsprite.setTextureRect(sf::IntRect(0, 0, 500, 300));
		break;
	case turtles:
		turtText.loadFromFile("turtle1.png");
		//rectText.left = 0; rectText.top = 0; rectText.width = 130; rectText.height = 240;
		objsprite.setScale(2.5f, 1.7f);
		objsprite.setPosition(sf::Vector2f(xLeft, 110.0));
		objsprite.setTexture(turtText, false);
		objsprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
		break;
	}
}

sf::Vector2f object::abspos(bool water)
{
	sf::Vector2f p = objsprite.getPosition();
	if (water) p = p + sf::Vector2f(80, 40);
	 else p = p + sf::Vector2f(80, 40);
	return p;
}

bool object::outOfBounds() {
	sf::Vector2f temp(objsprite.getPosition());
	if (temp.x > 1100.0 || temp.x < -180.0 || temp.y > 900.0 || temp.y < 0) {
		return true;
	}
	else return false;
}

void object::move(direction x, sf::Time elapsed, int levDif) {
	switch (levDif) {
	case 0:
		if (x == right) objsprite.move(150 * elapsed.asSeconds(), 0);
		else objsprite.move(-150 * elapsed.asSeconds(), 0);
		break;
	case 1:
		if (x == right) objsprite.move(250 * elapsed.asSeconds(), 0);
		else objsprite.move(-250 * elapsed.asSeconds(), 0);
		break;
	case 2:
		if (x == right) objsprite.move(350 * elapsed.asSeconds(), 0);
		else objsprite.move(-350 * elapsed.asSeconds(), 0);
		break;
	}
	//if (x == right) objsprite.move(150 * elapsed.asSeconds(), 0);
	//else objsprite.move(-150 * elapsed.asSeconds(), 0);
}

sf::FloatRect object::boundingBox()
{
	sf::FloatRect f = objsprite.getGlobalBounds();
	return f;
}

void object::displayObj(sf::RenderWindow &window)
{
	window.draw(objsprite);
}
