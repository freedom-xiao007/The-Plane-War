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
#include"prop.h"

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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(Gun::control()->cout_down==5){
            if(Prop::weapon_level>1){
                Bullet_one_hero::create_bullet(-15);
                Bullet_one_hero::create_bullet(5);
            }
            if(Prop::weapon_level>0){
                Bullet_one_hero::create_bullet(0);
                Bullet_one_hero::create_bullet(-10);
            }
            Bullet_one_hero::create_bullet(-5);
            Gun::control()->cout_down=0;
        }
        else{
            Gun::control()->cout_down++;
        }
    }
}
