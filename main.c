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
#include"ebullet.h"
#include"scenario.h"

int main()
{
	 Playgame* control=Playgame::getcontrol();//set a button to control game
	 sf::RenderWindow* window=control->getwindow();

	 //set backgroundmusic
	 sf::Music backgroundmusic;
	 if(!backgroundmusic.openFromFile("background.wav")){
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
			Playgame::getcontrol()->play();
			window->display();
	 }
}

