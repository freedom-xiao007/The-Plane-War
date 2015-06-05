#include"scenario.h"
#include"playgame.h"
#include<iostream>

Scenario* Scenario::it=new Scenario;

int Scenario::adjust=0;

bool Scenario::musicon=0;

float Scenario::speed=1;

int Scenario::level=1;

Scenario* Scenario::comeit()
{
	 return it;
}

double Scenario::grade=0;

Scenario::Scenario()
{
	 //set background
	 if(!tmap.loadFromFile("background1.jpg")){
	 }

smap.setTexture(tmap);

	  strgrade="0";

	 if(!gradefont.loadFromFile("ziti.ttf")){
	 }
	 gradetext.setFont(gradefont);
	 gradetext.setString(strgrade);
	 gradetext.setCharacterSize(20);
	 gradetext.setColor(sf::Color::White);

}

void Scenario::setscenario()
{
    if(Scenario::grade==50000){
        Scenario::level=2;
    }
    Scenario::adjustspeed();
	 Scenario::comeit()->setmap();
	 Scenario::comeit()->setscore();
}

void Scenario::setscore()
{
	 ssgrade << grade;
	 ssgrade >> strgrade;
	 ssgrade.clear();
	 gradetext.setString(strgrade);
	 Playgame::getcontrol()->windowtile->draw(gradetext);
}

void Scenario::setmap()
{
    if(Scenario::level==2){
        tmap.loadFromFile("background2.jpg");
    }
	 Playgame::getcontrol()->windowtile->draw(smap);
}

void Scenario::adjustspeed()
{
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)){
			if(Scenario::adjust==5){
			if(Scenario::speed<6){
			Scenario::speed+=1;
			Scenario::adjust=0;
			}}
			else{
				 ++Scenario::adjust;
			}
	 }
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)){
			if(Scenario::adjust==5){
			if(Scenario::speed>1){
				 Scenario::speed-=1;
				 Scenario::adjust=0;
			}}
			else{
				 ++Scenario::adjust;
			}
	 }
}
