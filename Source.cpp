#include <SFML/Graphics.hpp>
#include "frog.h"
#include "object.h"
#include "difficulty.h"
#include "levels.h"
#include "menu.h"
#include "lose.h"
#include <iostream>

//Generate water objects
void genRandObj(object &a, int p)
{
		switch (p)
		{
		case 0:
		case 2:
			a.editObj(object::logs, p);
			break;
		case 1:
			a.editObj(object::turtles, p);
			break;
		}
}

//generate car & dog objects 
void genRandObjCar(object &car, int p)
{
	switch (p) {
	case 0:
		car.editObj(object::redCar, p);
		break;
	case 1:
		car.editObj(object::buses, p);
		break;
	case 2:
		car.editObj(object::blueCar, p);
		break;
	case 3:
		car.editObj(object::dog, p);
		break;
	}
}

//put new object if out of bound for water
void streaming(object (&a)[3][3])
{
	for (int i = 0; i < 3; i++) {
		if (a[i][0].outOfBounds()) {
			a[i][0] = a[i][1];
			a[i][1] = a[i][2];
			genRandObj(a[i][2], i);
		}
	}
}
//put new object if out of bound for cars
void streamCars(object(&car)[4][3])
{
	for (int i = 0; i < 4; i++) {
		if (car[i][0].outOfBounds()) {
			car[i][0] = car[i][1];
			car[i][1] = car[i][2];
			genRandObjCar(car[i][2], i);
		}
	}
}

int main() {
	//menu
	Menu menu;
	bool gameEnter = false;
	int levDif;

	//lose or win
	lose l, w;
	bool dd = false;
	bool log = false;
	bool coCar = false;
	int dead = 0, deadCar = 0;
	bool deadflag=false;
	bool liveFlag = false;
	Music music;
	if (!music.openFromFile("music_1.ogg")) std::cout << "Error";
	music.setLoop(true);
	music.play();
	//movement of objects after each other
	int yt = 0, yt2 = 0;
	srand(time(NULL));
	object a[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) genRandObj(a[i][j], i);
	}
	object car[4][3];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) genRandObjCar(car[i][j], i);
	}
	

	sf::Clock frogClock, objClock, objStream, objClockCar, objStreamCar;
	sf::Time objElapsed, objElapsedCar;

	sf::RenderWindow window(VideoMode(1000, 800), "Frogger Game");
	frog f;

	while (window.isOpen()) {
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			menu.check(window, event, gameEnter, levDif);
			l.check(window, event, deadflag);
			w.check(window, event, deadflag);

			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				//movement of frog with keys
				frog::direction d;
				switch (event.key.code) {
				case sf::Keyboard::Up:
				case sf::Keyboard::W:
					d = frog::up;
					frogClock.restart();
					break;
				case sf::Keyboard::Down:
				case sf::Keyboard::S:
					d = frog::down;
					frogClock.restart();
					break;
				case sf::Keyboard::Right:
				case sf::Keyboard::D:
					d = frog::right;
					frogClock.restart();
					break;
				case sf::Keyboard::Left:
				case sf::Keyboard::A:
					d = frog::left;
					frogClock.restart();
					break;
				}
				if (f.getPos().y > 340.0) f.move(d, 55);
				else f.move(d, 70);
			}
		}
		//if frog Wins and crosses line
		if (f.getPos().y < 135.0)
		{
			liveFlag = true;
			//std::cout << "You WIn";
		}
		//if water objects collide with frog and frog syncs with it  
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
					if (f.collision(a[i][j], true)) {
						if (i == 1) f.move(frog::left, 4);
						else f.move(frog::right, 4);
						log = true;
						std::cout << "log";
					}
			}
		}
		//LOSING
		//if frog collides with cars or dog  
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++)
			{
				if (f.collision(car[i][j], false)) {
					std::cout << "yes";
					coCar = true;
				}
			}
		}
		if (coCar) deadCar++;
		else deadCar = 0;
		//if frog is in water but not on object (Dead or Lose)
		if (f.getPos().y > 135.0 && f.getPos().y < 340.0 && !log) {
			std::cout << "in water";
			dead++;
		} else dead = 0;
		//if any lose happens
		if (dead == 5 || deadCar == 5)
		{
			deadflag = true;
			dead = 0;
			deadCar = 0;
			coCar = false;
		}
		log = false;


		//Animation of frog
		if (frogClock.getElapsedTime().asSeconds() > 0.05f) f.animFrog();

		//Motion of turtles, logs
		objElapsed = objClock.getElapsedTime();
		streaming(a);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j < yt) {
					if (i == 1) a[i][j].move(object::left, objElapsed, levDif);
					else a[i][j].move(object::right, objElapsed, levDif);
				}
			}
		}
		if (objStream.getElapsedTime().asSeconds() > 3.0f) {
			yt++;
			objStream.restart();
		}
		objClock.restart();

		//Motion of cars & dog
		objElapsedCar = objClockCar.getElapsedTime();
		streamCars(car);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (j < yt) {
					switch (i) {
					case 0:
					case 2:
						car[i][j].move(object::left, objElapsedCar, levDif);
						break;
					case 1:
					case 3:
						car[i][j].move(object::right, objElapsedCar, levDif);
						break;
					}
				}
			}
		}
		if (objStreamCar.getElapsedTime().asSeconds() > 3.0f) {
			yt2++;
			objStreamCar.restart();
		}
		objClockCar.restart();

		//Displaying screen
		//white screen
        window.clear(Color::White);

		//Menu display 
		menu.display(window, event);

		//to display all objects if easy, medium, or hard button clicked on
		if (gameEnter) {
			//display water objects
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) a[i][j].displayObj(window);
			}
			//display frog
			f.display(window);
			//display cars and dog
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 3; j++) car[i][j].displayObj(window);
			}
		}

		//if frog loses, lose window appears
		if (deadflag || liveFlag) {
			f.setPos();
			if (deadflag) l.changebool();
			l.display(window);
		}
		
        window.display();
    }

    return 0;
}
