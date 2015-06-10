/*************************************************************************
	> File Name: enemy1.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 19时13分40秒
 ************************************************************************/

#include"enemy1.h"
#include"mywindow.h"
#include"hero.h"
#include"play.h"
#include"prop.h"

Enemy_one* Enemy_one::power = new Enemy_one;

Enemy_one* Enemy_one::control()
{
    return power;
}


Enemy_one* Enemy_one::create = Enemy_one::power;

Enemy_one* Enemy_one::head = Enemy_one::power;

Enemy_one* Enemy_one::link = Enemy_one::head;

int Enemy_one::cout_down = 0;


Enemy_one::Enemy_one()
{
    if(this->texture.loadFromFile("enemy1.png")){
        this->sprite.setTexture(this->texture);
    }

    if(this->tdisppear.loadFromFile("enemy11.png")){
        this->disppear.setTexture(this->tdisppear);
    }

    this->soudbuffer.loadFromFile("3660.wav");
    this->sound.setBuffer(soudbuffer);

    this->Y=0;
    this->X=rand() % 270;
    this->sprite.setPosition(this->X, this->Y);
    this->exist_son=0;
    this->on=0;
    this->alive=1;
    this->is_disppear=0;
    this->dis_cout_down=0;
}

void Enemy_one::move()
{
    MyWindow::control()->window.draw(this->sprite);
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->sprite.move(0.0, 3.0*Play::speed);
        this->Y+=3*Play::speed;
    }
}

void Enemy_one::fight()
{
    Enemy_one::clear_enemy();
    Enemy_one::show_enemy(Enemy_one::head);
}

void Enemy_one::create_enemy()
{
    Enemy_one::create->next = new Enemy_one;
    Enemy_one::create->exist_son=1;
    Enemy_one::create->on=1;
    Enemy_one::create=Enemy_one::create->next;
}

void Enemy_one::show_enemy(Enemy_one* heads)
{
    if(heads->on==1){
        if(heads->alive==1){
            heads->move();
            if(heads->sprite.getGlobalBounds().intersects(Hero::control()->sprite.getGlobalBounds())&&Hero::control()->alive==1){
                if(Prop::control()->is_fence==0){
                Hero::control()->alive=0;
                }
                heads->alive=0;
            }
        }
        else{
            if(heads->is_disppear==0){
                heads->dis_step(heads);
                MyWindow::control()->window.draw(heads->disppear);
            }
        }
        if(heads->exist_son==1){
            Enemy_one::show_enemy(heads->next);
        }
    }
}

void Enemy_one::clear_enemy()
{
    if(Enemy_one::head->on==1){
        if(Enemy_one::head->Y==500||(head->is_disppear==1&&head->alive==0)){
            Enemy_one::link=Enemy_one::head;
            Enemy_one::head=Enemy_one::head->next;
            delete Enemy_one::link;
        }
    }
}

sf::Sprite Enemy_one::get_sprite()
{
    return sprite;
}

void Enemy_one::dis_step(Enemy_one* enemy)
{
    enemy->disppear.setPosition(enemy->sprite.getPosition());
    if(enemy->dis_cout_down==5){
        enemy->tdisppear.loadFromFile("enemy12.png");
        enemy->sound.play();
    }
    if(enemy->dis_cout_down==15){
        enemy->tdisppear.loadFromFile("enemy13.png");
    }
    if(enemy->dis_cout_down==25){
        enemy->tdisppear.loadFromFile("enemy14.png");
    }
    if(enemy->dis_cout_down==30){
        enemy->tdisppear.loadFromFile("enemy15.png");
        enemy->is_disppear=1;
    }
    else{
        ++enemy->dis_cout_down;
    }
}
