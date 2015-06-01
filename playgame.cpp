#include"playgame.h"
#include<SFML/Graphics.hpp>
#include"plane.h"
#include"bullet.h"
#include"enemy.h"
#include"scenario.h"

#define TT

int Playgame::i=0;

Playgame::Playgame()
{
	 windowtile=new sf::RenderWindow(sf::VideoMode(300, 500), "The-Play-War");
}

void Playgame::play()
{
	 windowtile->clear();
     Scenario::setscenario();
	 Plane::comeit()->show();
	 Bullet::fire(Plane::comeit());
	 Enemy::fight(Plane::comeit());
	 windowtile->display();
}

sf::RenderWindow* Playgame::getwindow()
{
	 return windowtile;
}

Playgame* Playgame::getcontrol()
{
	 return power;
}

Playgame* Playgame::power=new Playgame;


