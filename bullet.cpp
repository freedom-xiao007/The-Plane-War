#include"bullet.h"
#include"enemy.h"
#include"plane.h"
#include"playgame.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<SFML/Graphics.hpp>

#define TT

int Bullet::i=0;

int Bullet::j=0;

sf::Time Bullet::time1=sf::seconds(0.1f);

sf::Time Bullet::time2=sf::seconds(1.0f);

Bullet* Bullet::create=new Bullet;

Bullet* Bullet::bullethead=Bullet::create;

Bullet* Bullet::bulletline=Bullet::bullethead;

Bullet* Bullet::come=Bullet::create;

Bullet* Bullet::comeit()
{
	 return come;
}

Bullet::Bullet()
{
	 if(!tbullet.loadFromFile("shoot.jpg")){
			std::cout<<"ENEMY"<<std::endl;
	 }
	 sbullet.setTexture(tbullet);
	 if(explosive.loadFromFile("explosive.wav")){
			std::cout<<"EWWW"<<std::endl;
	 }
	 this->explosivemusic.setBuffer(explosive);
	 this->on=0;
	 this->existson=0;
	 this->x=470;
	 this->bulletdead=0;
}

void Bullet::crete_bullet(Plane* plane)
{
	 Bullet::create->next=new Bullet;
	 Bullet::create->sbullet.setPosition(plane->splane.getPosition());
	 Bullet::create->on=1;
	 Bullet::create->existson=1;
	 if(Bullet::create->existson==1){
	 Bullet::create=create->next;
#ifndef T
	 std::cout<<"CREATE BULLET"<<std::endl;
#endif
	 }
}

void Bullet::show_bullet(Bullet* head)
{
	 if(head->on==1){
						Playgame::getcontrol()->windowtile->draw(head->sbullet);
				 if(head->existson==1){
						Bullet::show_bullet(head->next);
				 }}
}

void Bullet::move_bullet(Bullet* head, Enemy* eheads)
{
	 if(head->on==1){
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				 head->sbullet.move(0.0, -5.0);
				 head->checkcllision(Enemy::enemyhead);
				 head->x-=5;
			if(head->existson==1){
				 Bullet::move_bullet(head->next, eheads);
			}}}
}

void Bullet::clear_bullet()
{
	 if(Bullet::bullethead->on==1){
			if(Bullet::bullethead->existson==1){
				 if(Bullet::bullethead->x<0){
						Bullet::bullethead=Bullet::bullethead->next;
						delete Bullet::bulletline;
						Bullet::bulletline=Bullet::bullethead;
#ifndef T
						std::cout<<"DELETE BULLET"<<std::endl;
#endif
				 }
			}
	 }
}

void Bullet::fire(Plane* plane)
{
	 Bullet::clear_bullet();
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			if(Bullet::i==4){
				 Bullet::crete_bullet(plane);
				 Bullet::i=0;
			}
			else{
				 ++Bullet::i;
			}}
	 Bullet::show_bullet(Bullet::bullethead);
	 Bullet::move_bullet(Bullet::bullethead, Enemy::enemyhead);
}

void Bullet::checkcllision(Enemy* head)
{
	 if(this->bulletdead==0){//检查子弹是否存在
	 if(this->sbullet.getGlobalBounds().intersects(head->senemy.getGlobalBounds())&&head->enemydead==0){//检查是否碰撞和敌机是否存在
			this->explosivemusic.play();
			this->bulletdead=1;//设定子弹死亡
			head->enemydead=1;//设定敌机死亡
#define BB
#ifndef B
			std::cout<<"CLLISION"<<std::endl;
#endif
			this->tbullet.loadFromFile("disppear.png");
	 }
	 else{
			if(head->existson==1){
				 checkcllision(head->next);
			}
	 }}
}

void Bullet::disppear(Enemy* enemy)
{
	 enemy->disppear=1;
	 std::cout<<enemy->disppear<<std::endl;
}
