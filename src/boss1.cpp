/*************************************************************************
  > File Name: boss1.cpp
  > Author: lw
  > Mail: 1243925457@qq.com
  > Created Time: 2015年06月10日 星期三 00时46分30秒
 ************************************************************************/

#include<iostream>
#include"boss1.h"
#include"hero.h"
#include"mywindow.h"
#include"kill_score.h"
#include"bullet_one.enemy.h"

Boss1* Boss1::power = new Boss1;

Boss1* Boss1::control()
{
    return power;
}

Boss1::Boss1()
{
    this->texture.loadFromFile("boss1.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(0, 50);
    this->soudbuffer.loadFromFile("explosive_boss1.wav");
    this->sound.setBuffer(soudbuffer);
    this->X=0;
    this->blood=200;
    this->l_move=0;
    this->r_move=0;
    this->fire_cout_down=0;
    this->is_disppear=0;
    this->alive=1;
    this->dis_cout_down=0;
    this->on=0;
}

void Boss1::fight()
{
    if(Boss1::control()->blood<0){
        Boss1::control()->on=0;
    }
    if(Boss1::control()->blood<=0){
        Boss1::control()->alive=0;
    }

    Boss1::control()-> move();
}

void Boss1::move()
{
    if(alive==1){
        if(sprite.getGlobalBounds().intersects(Hero::control()->sprite.getGlobalBounds())&&Hero::control()->alive==1){
            Hero::control()->alive=0;
            blood-=1;
        }
    }

    if(blood>0){
        fire();
        if(this->X==0){
            this->r_move=1;
            this->l_move=0;
        }
        if(this->X==200){
            this->r_move=0;
            this->l_move=1;
        }
        if(this->r_move==1){
            this->sprite.move(1.0, 0.0);
            this->X+=1;
        }
        if(this->l_move==1){
            this->sprite.move(-1.0, 0.0);
            this->X-=1;
        }
    }
    else{
        dis_step();
    }
    if(is_disppear==0){
        MyWindow::control()->window.draw(this->sprite);
    }
}

void Boss1::fire()
{
    if(this->fire_cout_down==50){
        Bullet_one_enemy::create_bullet(sprite, 0);
        Bullet_one_enemy::create_bullet(sprite, 100);
        Bullet_one_enemy::create_bullet(sprite, 50);
        this->fire_cout_down=0;
    }
    else{
        this->fire_cout_down++;
    }
}

sf::Sprite Boss1::get_sprite()
{
    return sprite;
}

void Boss1::dis_step()
{
    if(is_disppear==0){
        if(dis_cout_down==50){
            texture.loadFromFile("boss11.png");
            sound.play();
        }
        if(dis_cout_down==100){
            texture.loadFromFile("boss12.png");
        }
        if(dis_cout_down==150){
            texture.loadFromFile("boss13.png");
            is_disppear=1;
            dis_cout_down=0;
        }
        else{
            ++dis_cout_down;
        }
    }
}
