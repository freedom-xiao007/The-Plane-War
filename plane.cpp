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
    if(!tplane.loadFromFile("hero.png")){
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
        splane.move(-5, 0.0);
        x-=5;
    }
}

void Plane::rmove()
{
    if(x<270){
        splane.move(5, 0.0);
        x+=5;
    }
}

void Plane::umove()
{
    if(y>0){
        splane.move(0.0, -5);
        y-=5;
    }
}

void Plane::dmove()
{
    if(y<470){
        splane.move(0.0, 5);
        y+=5;
    }
}

void Plane::show()
{
    if(this->blood==0){
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
            if(tplane.loadFromFile("enemy3.png")){
            }
            if(dis==5){
                if(tplane.loadFromFile("hero.png")){
                    planedead=0;
                    dis=0;
                    blood-=1;
                }
            }
            else{
                ++dis;
            }
        }
        Playgame::getcontrol()->windowtile->draw(Plane::hero->splane);
    }
}

