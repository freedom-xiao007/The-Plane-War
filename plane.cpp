#include"plane.h"
#include"playgame.h"
#include<iostream>
#include<string.h>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

Plane* Plane::hero=new Plane;

Plane* Plane::comeit()
{
	 return hero;
}

Plane::Plane()
{
	 x=150;
	 y=470;
	 if(!tplane.loadFromFile("plane.png")){
			std::cout<<"ERROW"<<std::endl;
	 }
	 splane.setTexture(tplane);
	 splane.setPosition(sf::Vector2f(150.0, 470.0));
	 planedead=0;
	 dis=0;
}

void Plane::lmove()
{
	 if(x>0){
			splane.move(-3.0, 0.0);
			x-=3;
	 }
}

void Plane::rmove()
{
	 if(x<270){
			splane.move(3.0, 0.0);
			x+=3;
	 }
}

void Plane::umove()
{
	 if(y>0){
			splane.move(0.0, -3);
			y-=3;
	 }
}

void Plane::dmove()
{
	 if(y<470){
			splane.move(0.0, 3.0);
			y+=3;
	 }
}

void Plane::show()
{
if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			lmove();
	 }
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			rmove();
	 }
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			umove();
	 }
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			dmove();
	 }

	 if(planedead==1){
				 if(this->dis<5){
				 this->tplane.loadFromFile("enemy1.png");
				 }
				 if(this->dis==10){
						this->tplane.loadFromFile("enemy2.png");
				 }
				 if(this->dis==15){
						this->tplane.loadFromFile("enemy3.png");
				 }
				 if(this->dis==20){
						this->tplane.loadFromFile("disppear.png");
				 }
				 else{
						++(this->dis);
				 }
	 }
Playgame::getcontrol()->windowtile->draw(Plane::hero->splane);
}

