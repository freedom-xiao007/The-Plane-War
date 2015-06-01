#ifndef BULLET

#include<iostream>
#include<string.h>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
class Enemy;
class Plane;
class Playgame;



class Bullet
{
	 public:
			Bullet();
			static void move_bullet(Bullet* head, Enemy* eheads);
			static void crete_bullet(Plane* plane);
			static void clear_bullet();
			static void show_bullet(Bullet* head);
			static void fire(Plane* plane);
			static Bullet* comeit();
			static Bullet* create;
			static Bullet* bullethead;
			static Bullet* bulletline;
			void checkcllision(Enemy* head);
			bool on;
			bool existson;
			Bullet* next;
			int x;
		  sf::SoundBuffer explosive;
			sf::Sound explosivemusic;
			static int j;
			static int i;
			bool bulletdead;
			sf::Clock clock;
			sf::Texture tbullet;
			sf::Sprite sbullet;
			static Bullet* come;
};



#endif
