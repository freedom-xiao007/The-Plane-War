/*************************************************************************
  > File Name: enemy1.cpp
  > Author: lw
  > Mail: 1243925457@qq.com
  > Created Time: 2015年06月06日 星期六 19时13分40秒
 ************************************************************************/

#include"enemy2.h"
#include"mywindow.h"
#include"hero.h"
#include"bullet_one.enemy.h"
#include"gun.h"
#include"gun_e.h"

Enemy_two* Enemy_two::power = new Enemy_two;

Enemy_two* Enemy_two::control()
{
    return power;
}


Enemy_two* Enemy_two::create = Enemy_two::power;

Enemy_two* Enemy_two::head = Enemy_two::power;

Enemy_two* Enemy_two::link = Enemy_two::head;

int Enemy_two::cout_down = 0;

int Enemy_two::fire_cout_down = 0;

Enemy_two::Enemy_two()
{
    if(this->texture.loadFromFile("enemy2.png")){
        this->sprite.setTexture(this->texture);
    }

    if(this->tdisppear.loadFromFile("enemy11.png")){
        this->disppear.setTexture(tdisppear);
    }

    if(this->soudbuffer.loadFromFile("explosive1.wav")){
        this->sound.setBuffer(soudbuffer);
    }

    this->Y=50 + rand() % 150;
    this->X=rand() % 270;
    this->sprite.setPosition(this->X, this->Y);
    this->exist_son=0;
    this->on=0;
    this->alive=1;
    this->lmove=0;
    this->rmove=0;
    this->is_move=0;
    this->cout_down_b=0;
    this->is_disppear=0;
    this->dis_cout_down=0;
}

void Enemy_two::move()
{
    MyWindow::control()->window.draw(this->sprite);
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        if(this->is_move==0){
            if(this->X>=140){
                this->rmove=1;
                this->is_move=1;
            }
            else{
                this->lmove=1;
                this->is_move=1;
            }
        }
        if(this->cout_down_b==30){
            if(this->rmove==1&&this->alive==1){
                this->sprite.move(-3.0, 0.0);
                this->X-=3;
                this->cout_down_b=0;
            }
            else{
                this->sprite.move(3.0, 0.0);
                this->X+=3;
                this->cout_down_b=0;
            }
        }
        else{
            ++this->cout_down_b;
        }
    }
}

void Enemy_two::fight()
{
    Enemy_two::clear_enemy();
    Enemy_two::show_enemy(Enemy_two::head);
}

void Enemy_two::create_enemy()
{
    Enemy_two::create->next = new Enemy_two;
    Enemy_two::create->exist_son=1;
    Enemy_two::create->on=1;
    Enemy_two::create=Enemy_two::create->next;
}

void Enemy_two::show_enemy(Enemy_two* heads)
{
        if(heads->alive==1){
            heads->move();
            Gun_e::fight(21, heads);
            if(heads->sprite.getGlobalBounds().intersects(Hero::control()->sprite.getGlobalBounds())&&Hero::control()->alive==1){
                Hero::control()->alive=0;
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
            Enemy_two::show_enemy(heads->next);
        }
}

void Enemy_two::clear_enemy()
{
    if(Enemy_two::head->on==1){
        if((Enemy_two::head->X>300&&Enemy_two::head->is_disppear==1)||(Enemy_two::head->is_disppear==1&&Enemy_two::head->X<0)||(Enemy_two::head->is_disppear==1&&Enemy_two::head->alive==0)){
            Enemy_two::link=Enemy_two::head;
            Enemy_two::head=Enemy_two::head->next;
            delete Enemy_two::link;
        }
    }
}

sf::Sprite Enemy_two::get_sprite()
{
    return sprite;
}

void Enemy_two::fire()
{
}

void Enemy_two::dis_step(Enemy_two* enemy)
{
    enemy->disppear.setPosition(enemy->sprite.getPosition());
    if(enemy->dis_cout_down==5){
        enemy->tdisppear.loadFromFile("enemy22.png");
        enemy->sound.play();
    }
    if(enemy->dis_cout_down==15){
        enemy->tdisppear.loadFromFile("enemy23.png");
    }
    if(enemy->dis_cout_down==25){
        enemy->tdisppear.loadFromFile("enemy24.png");
    }
    if(enemy->dis_cout_down==30){
        enemy->tdisppear.loadFromFile("enemy25.png");
        enemy->is_disppear=1;
    }
    else{
        ++enemy->dis_cout_down;
    }
}
