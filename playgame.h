#ifndef PLAY
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<sstream>
#include<stdlib.h>
#include<string>

class Plane;

class Playgame
{
	 public:
			Playgame();
			static Playgame* getcontrol();
			sf::RenderWindow* getwindow();
			void play();
			static Playgame* power;
			static int i;
			sf::RenderWindow* windowtile;
	};

#endif

