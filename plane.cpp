#include"plane.h"
#include"playgame.h"
#include<iostream>
#include<string.h>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"scenario.h"

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
	 blood=3;
	 dis=0;
}

void Plane::lmove()
{
	 if(x>0){
			splane.move(-Scenario::speed, 0.0);
			x-=Scenario::speed;
	 }
}

void Plane::rmove()
{
	 if(x<270){
			splane.move(Scenario::speed, 0.0);
			x+=Scenario::speed;
	 }
}

void Plane::umove()
{
	 if(y>0){
			splane.move(0.0, -Scenario::speed);
			y-=Scenario::speed;
	 }
}

void Plane::dmove()
{
	 if(y<470){
			splane.move(0.0, Scenario::speed);
			y+=Scenario::speed;
	 }
}

void Plane::show()
{
	 if(this->blood==0){
			std::cout<<"DEAD!!!!!!!!!!!!"<<std::endl;
	 }
	 else{
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
				 std::cout<<"sdfsdfsdfsdfdsf"<<std::endl;
				 if(this->dis==10){
						this->tplane.loadFromFile("enemy2.png");
				 }
				 if(this->dis==15){
						this->tplane.loadFromFile("enemy3.png");
				 }
				 if(this->dis==20){
						this->tplane.loadFromFile("plane.png");
						this->blood-=1;
						this->planedead=0;
						this->dis=0;
				 }
				 else{
						++(this->dis);
				 }
	 }
	 Playgame::getcontrol()->windowtile->draw(Plane::hero->splane);
	 }
}

