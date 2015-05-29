#include"enemy.h"
#include"playgame.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<SFML/Graphics.hpp>
#include"bullet.h"
#include"ebullet.h"

#define T

int Enemy::i=0;

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
	 if(!tenemy.loadFromFile("enemy.png")){
			std::cout<<"ENEMY"<<std::endl;
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
#ifndef T
	 std::cout<<"CREATE ENEMY"<<std::endl;
#endif
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
						head->tenemy.loadFromFile("disppear.png");
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
			head->fire(head, plane);
	 if(head->on==1){
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				 head->senemy.move(0.0, 0.5);
				 head->y+=1;
			}
			if(head->existson==1){
				 Enemy::move_enemy(head->next, bheads, plane);
			}}
}

void Enemy::clear_enemy()
{
#ifndef B
	 if(Enemy::enemyhead->on==1){
			if(Enemy::enemyhead->existson==1){
				 if(Enemy::enemyhead->y>1000){
						Enemy::enemyhead=Enemy::enemyhead->next;
						delete Enemy::enemyline;
						Enemy::enemyline=Enemy::enemyhead;
#ifndef T
						std::cout<<"DELETE ENEMY"<<std::endl;
#endif
				 }
			}
	 }
#endif
}

void Enemy::fight(Plane* plane)
{
	 Enemy::clear_enemy();
	 if(Enemy::i==100){
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

