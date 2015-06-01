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
	 sf::RenderWindow* window=Playgame::getcontrol()->getwindow();//得到窗口的控制

	 //set backgroundmusic
	 sf::Music backgroundmusic;
	 if(!backgroundmusic.openFromFile("background.wav")){
			std::cout<<"ERRW"<<std::endl;
	 }
	 backgroundmusic.play();

     //控制游戏速度
	 window->setVerticalSyncEnabled(true);
	 window->setFramerateLimit(60);
	 srand(time(0));//设置随机数

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

