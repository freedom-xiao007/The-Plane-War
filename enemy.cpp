#include"enemy.h"
#include"playgame.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<SFML/Graphics.hpp>
#include"bullet.h"
#include"ebullet.h"
#include"plane.h"
#include"scenario.h"


int Enemy::i=0;

int Enemy::speed=0.5;

int Enemy::move=5;
 
int Enemy::enemystyle=0;

Enemy* Enemy::create=new Enemy;

Enemy* Enemy::enemyhead=Enemy::create;

Enemy* Enemy::enemyline=Enemy::enemyhead;

Enemy* Enemy::come=Enemy::create;

Enemy* Enemy::comeit()
{
    return come;
}

Enemy::Enemy()
{
    Enemy::enemystyle=rand() % 2;
    if(Enemy::enemystyle==0){
       if(this->tenemy.loadFromFile("enemy.png")){} 
    }
    if(Enemy::enemystyle==1){
        if(this->tenemy.loadFromFile("1enemy.png")){}
    }
    senemy.setTexture(tenemy);
    this->on=0;
    this->existson=0;
    this->enemydead=0;
    this->disppear=0;
    this->y=0;
    this->dis=0;
}

void Enemy::crete_enemy()
{
    Enemy::create->next=new Enemy;
    srand(time(0));
    Enemy::create->yy=rand() % 270;
    Enemy::create->senemy.setPosition(sf::Vector2f(Enemy::create->yy, 0.0));
    Enemy::create->on=1;
    Enemy::create->existson=1;
    if(Enemy::create->existson==1){
        Enemy::create=create->next;
    }
}

void Enemy::show_enemy(Enemy* head)
{
    if(head->on==1){
        if(head->enemydead==1){
            if(head->dis<5){
                head->tenemy.loadFromFile("enemy1.png");
            }
            if(head->dis==10){
                head->tenemy.loadFromFile("enemy2.png");
            }
            if(head->dis==15){
                head->tenemy.loadFromFile("enemy3.png");
            }
            if(head->dis==20){
                head->tenemy.loadFromFile("dispear.png");
                head->senemy.move(0.0, 100.0);
                head->y+=100;
            }
            else{
                ++(head->dis);
            }
        }
        Playgame::getcontrol()->windowtile->draw(head->senemy);
        if(head->existson==1){
            Enemy::show_enemy(head->next);
        }}
}

void Enemy::move_enemy(Enemy* head, Bullet* bheads, Plane* plane)
{
    if(head->senemy.getGlobalBounds().intersects(Plane::comeit()->splane.getGlobalBounds())&&head->enemydead==0){//检查是否碰撞和敌机是否存在
        head->enemydead=1;
        Plane::comeit()->planedead=1;
    }
    head->fire(head, plane);
    if(head->on==1){
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            if(Scenario::speed<=2){
                if(head->enemydead==0){
                    if(Enemy::move==5){
                        head->rate=rand() % 2;
                        if(head->rate==0){
                            head->senemy.move(10, 5);
                            Enemy::move=0;
                        }
                        else{
                            head->senemy.move(-10, 5);
                            Enemy::move=0;
                        }
                    }  
                    else{
                        ++Enemy::move;
                    }
                }
            }
            if(Scenario::speed>2){
                head->senemy.move(0.0, 3.0);
                head->y+=3;
            }
        }
        if(head->existson==1){
            Enemy::move_enemy(head->next, bheads, plane);
        }}
}

void Enemy::clear_enemy()
{
    if(Enemy::enemyhead->on==1){
        if(Enemy::enemyhead->existson==1){
            if(Enemy::enemyhead->y>1000){
                Enemy::enemyhead=Enemy::enemyhead->next;
                delete Enemy::enemyline;
                Enemy::enemyline=Enemy::enemyhead;
            }
        }
    }
}

void Enemy::fight(Plane* plane)
{
    Enemy::clear_enemy();
    if(Enemy::i==20){
        Enemy::crete_enemy();
        Enemy::i=0;
    }
    else{
        ++Enemy::i;
    }
    Enemy::show_enemy(Enemy::enemyhead);
    Enemy::move_enemy(Enemy::enemyhead, Bullet::bullethead, plane);
}

void Enemy::fire(Enemy* enemy, Plane* plane)
{
    EBullet::fire(enemy, plane);
}

