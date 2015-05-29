#ifndef PLANE
#include<iostream>
#include<string.h>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>


class Plane
{
	 public:
			Plane();
			void lmove();
			void umove();
			void rmove();
			void dmove();
			void show();
			int x;
			int y;
			int planedead;
			int dis;
			sf::Texture tplane;
			sf::Sprite splane;
			static Plane* hero;
			static Plane* comeit();

};

#endif
