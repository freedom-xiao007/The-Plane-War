#ifndef EBULLET

#include<iostream>
#include<string.h>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
class Enemy;
class Plane;
class Playgame;



class EBullet
{
	 public:
			EBullet();
			void disppear(Enemy* enemy);
			static void move_bullet(EBullet* head, Plane* plane);
			static void crete_bullet(Enemy* enemy);
			static void clear_bullet();
			static void show_bullet(EBullet* head);
			static void fire(Enemy* enemys, Plane* plane);
			static EBullet* comeit();
			static EBullet* create;
			static EBullet* bullethead;
			static EBullet* bulletline;
			void checkcllision(Plane* plane);
			bool on;
			bool existson;
			EBullet* next;
			int x;
		  sf::SoundBuffer explosive;
			sf::Sound explosivemusic;
			static int j;
			static int i;
			bool bulletdead;
			sf::Clock clock;
			static sf::Time time1;
			static sf::Time time2;
			sf::Texture tbullet;
			sf::Sprite sbullet;
			static EBullet* come;
};



#endif
