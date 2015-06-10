/*************************************************************************
	> File Name: laser.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月10日 星期三 17时59分45秒
 ************************************************************************/

#include<iostream>
#include"laser.h"
#include"boss1.h"
#include"enemy1.h"
#include"enemy2.h"
#include"hero.h"
#include"kill_score.h"
#include"skill_score.h"
#include"mywindow.h"

Laser* Laser::power = new Laser;

Laser* Laser::control()
{
return power;
}

Laser::Laser()
{
    this->tlaser1.loadFromFile("laser1.png");
    this->tlaser1.loadFromFile("laser2.png");
    this->slaser.setTexture(tlaser1);
    this->slaser.setPosition(300, 350);
    this->texture.loadFromFile("laser.png");
    this->sprite.setTexture(texture);
    this->cout_down=0;
    this->is_fire=0;
}

void Laser::fight()
{
    power->fire();
    power->move();
}
 
void Laser::move()
{
    if(is_fire==1){
    this->check_cllision();
    this->check_cllision(Enemy_one::head);
    this->check_cllision(Enemy_two::head);
    sprite.setPosition(Hero::control()->sprite.getPosition().x-15,-(470-Hero::control()->sprite.getPosition().y));
    MyWindow::control()->window.draw(slaser);
}
}

void Laser::fire()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        is_fire=1;
    } 
    if(is_fire==1){
        MyWindow::control()->window.draw(sprite);
        if(cout_down==200){
            is_fire=0;
            cout_down=0;
        }
        else{
            ++cout_down;
        }
    }
}

void Laser::check_cllision()
{
if(Boss1::control()->on==1&&this->sprite.getGlobalBounds().intersects(Boss1::control()->get_sprite().getGlobalBounds())){
        if(Boss1::control()->blood>0){
        Boss1::control()->blood-=1;
        }        
        std::cout<<Boss1::control()->blood<<std::endl;
    }

}

void Laser::check_cllision(Enemy_one* heads)
{
    if(heads->alive==1&&sprite.getGlobalBounds().intersects(heads->get_sprite().getGlobalBounds())){
        heads->alive=0;
        Kill_score::k_score+=10;
        Skill_score::k_score+=1;
    }
    else{
        if(heads->exist_son==1){
            this->check_cllision(heads->next);
        }
    }
}

void Laser::check_cllision(Enemy_two* heads)
{
    if(heads->alive==1&&this->sprite.getGlobalBounds().intersects(heads->get_sprite().getGlobalBounds())){
        heads->alive=0;
        Kill_score::k_score+=10;
        Skill_score::k_score+=1;
    }
    else{
        if(heads->exist_son==1){
            this->check_cllision(heads->next);
        }
    }
}


