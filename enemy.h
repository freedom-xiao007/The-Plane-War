#ifndef ENEMY
#include<iostream>
#include<string.h>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>

class Bullet;
class Playgame;
class Plane;

class Enemy
{
	 public:
			Enemy();
            static int speed;
			static void move_enemy(Enemy* head, Bullet* bheads, Plane* plane);
			void fire(Enemy* enemys, Plane* plane);
			static void crete_enemy();
			static void clear_enemy();
			static void show_enemy(Enemy* head);
			static void fight(Plane* plane);
			static Enemy* comeit();
			static Enemy* create;
			static Enemy* enemyhead;
			static Enemy* enemyline;
			bool enemydead;
			bool on;
			bool disppear;
			bool existson;
			Enemy* next;
			int y;
			int rate;
			int dis;
			float yy;
			static int i;
			sf::Texture tenemy;
			sf::Sprite senemy;
			static Enemy* come;
};

#endif
