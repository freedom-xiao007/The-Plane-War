#include<iostream>
#include<string.h>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"enemy.h"
#include"bullet.h"
#include"plane.h"
#include"playgame.h"

int main()
{
	 Playgame* control=Playgame::getcontrol();//set a button to control game
	 sf::RenderWindow* window=control->getwindow();

	 //set background
	 sf::Texture tmap;
	 if(!tmap.loadFromFile("background1.jpg")){
			std::cout<<"ERROW"<<std::endl;
	 }
	 sf::Sprite smap(tmap);

	 //set hero
	 Plane hero;

	 //set enemy
	 Enemy* holle=Enemy::comeit();

	 //set bullet
	 Bullet* bullets=Bullet::comeit();

	 //set backgroundmusic
	 sf::Music backgroundmusic;
	 if(!backgroundmusic.openFromFile("background1.wav")){
			std::cout<<"ERRW"<<std::endl;
	 }
	 backgroundmusic.play();

	 window->setVerticalSyncEnabled(true);
	 window->setFramerateLimit(60);
	 srand(time(0));

	 //window behavior
	 while(window->isOpen())
	 {
			sf::Event event;
			while(window->pollEvent(event))
			{
				 if(event.type == sf::Event::Closed){
						window->close();
				 }
			}


			window->clear();
			window->draw(smap);
			window->draw(hero.splane);
			control->play(hero);
			holle->Enemy::fight();
			bullets->Bullet::fire(hero);
			window->display();
	 }
}

