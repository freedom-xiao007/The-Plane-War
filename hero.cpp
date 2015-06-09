/*************************************************************************
	> File Name: hero.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 11时59分55秒
 ************************************************************************/

#include"mywindow.h"
#include"hero.h"
#include"gun.h"
#include"bullet_one_hero.h"

Hero* Hero::power = new Hero;

Hero* Hero::control()
{
    return power;
}

Hero::Hero()
{
    if(this->texture.loadFromFile("hero.png")){
            this->sprite.setTexture(this->texture);
            }
    this->sprite.setPosition(150.0, 470.0);
    this->alive=1;
    this->X=150.0;
    this->Y=470.0;
    this->level=0;
}

void Hero::fight()
{
    this->move();
    this->fire();
}

void Hero::move()
{
    MyWindow::control()->window.draw(this->sprite);
    this->lfly();
    this->dfly();
    this->rfly();
    this->ufly();
}

void Hero::lfly()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(this->X>0){
            this->sprite.move(-3.0, 0.0);
            this->X-=3;
        }
    }
}

void Hero::rfly()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(this->X<270){
            this->sprite.move(3.0, 0.0);
            this->X+=3;
        }
    }
}
 
void Hero::ufly()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(this->Y>0){
            this->sprite.move(0.0, -3.0);
            this->Y-=3;
        }
    }
}

void Hero::dfly()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if(this->Y<470){
            this->sprite.move(0.0, 3.0);
            this->Y+=3;
        }
    }
}

void Hero::fire()
{
    Gun::fight(11);
}
