#include"ebullet.h"
#include"enemy.h"
#include"plane.h"
#include"playgame.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<SFML/Graphics.hpp>


int EBullet::i=0;

int EBullet::j=0;

sf::Time EBullet::time1=sf::seconds(0.1f);

sf::Time EBullet::time2=sf::seconds(1.0f);

EBullet* EBullet::create=new EBullet;

EBullet* EBullet::bullethead=EBullet::create;

EBullet* EBullet::bulletline=EBullet::bullethead;

EBullet* EBullet::come=EBullet::create;

EBullet* EBullet::comeit()
{
    return come;
}

EBullet::EBullet()
{
    if(!tbullet.loadFromFile("shoot.png")){
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

void EBullet::crete_bullet(Enemy* enemy)
{
    EBullet::create->next=new EBullet;
    EBullet::create->sbullet.setPosition(enemy->senemy.getPosition());
    EBullet::create->on=1;
    EBullet::create->existson=1;
    if(EBullet::create->existson==1){
        EBullet::create=EBullet::create->next;
    }
}

void EBullet::show_bullet(EBullet* head)
{
    if(head->on==1){
        Playgame::getcontrol()->windowtile->draw(head->sbullet);
        if(head->existson==1){
            EBullet::show_bullet(head->next);
        }}
}

void EBullet::move_bullet(EBullet* head, Plane* plane)
{
    if(head->on==1){
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            if(head->bulletdead==0){
                head->sbullet.move(0.0, 4.0);
                head->checkcllision(plane);
                head->x+=2;
            }
            else{
                if(EBullet::j==5){
                    head->sbullet.move(0.0, 100.0);
                    head->x+=100;
                    EBullet::j=0;
                }
                else{
                    ++EBullet::j;
                }
            }
            if(head->existson==1){
                EBullet::move_bullet( head->next, plane );
            }}}
}

void EBullet::clear_bullet()
{
    if(EBullet::bullethead->on==1){
        if(EBullet::bullethead->existson==1){
            if(EBullet::bullethead->x>1000){
                EBullet::bullethead=EBullet::bullethead->next;
                delete EBullet::bulletline;
                EBullet::bulletline=EBullet::bullethead;
            }
        }
    }
}

void EBullet::fire(Enemy* enemys, Plane* plane)
{
    if(enemys->enemydead==0){
        EBullet::clear_bullet();
        EBullet::i=rand() % 70;
        if(EBullet::i==4){
            EBullet::crete_bullet(enemys);
            EBullet::i=0;
        }
        EBullet::show_bullet(EBullet::bullethead);
        EBullet::move_bullet(EBullet::bullethead, plane);
    }
}

void EBullet::checkcllision(Plane* plane)
{
    if(this->bulletdead==0){//检查子弹是否存在
        if(this->sbullet.getGlobalBounds().intersects(plane->splane.getGlobalBounds())&&plane->planedead==0){//检查是否碰撞和敌机是否存在
            this->explosivemusic.play();
            this->bulletdead=1;//设定子弹死亡
            plane->planedead=1;//设定敌机死亡
            this->tbullet.loadFromFile("disppear.png");
        }
    }
}

