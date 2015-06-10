/*************************************************************************
	> File Name: blood_hero.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 13时47分41秒
 ************************************************************************/

#include<iostream>
#include"blood_hero.h"
#include"mywindow.h"
#include"hero.h"

int Blood_hero::blood_hero=4;

Blood_hero::Blood_hero()
{
    this->tblood1.loadFromFile("hero_blood1.jpg");
    this->tblood2.loadFromFile("hero_blood2.jpg");
    this->tblood3.loadFromFile("hero_blood3.jpg");
    this->tblood4.loadFromFile("hero_blood4.jpg");
    this->sblool.setTexture(tblood4);
    this->sblool.setPosition(0.0, 500.0);
}

void Blood_hero::blood()
{
    if(Hero::control()->alive==0){
        this->blood_hero-=1;
        Hero::control()->alive=1;
    }

    if(this->blood_hero==3){
        this->sblool.setTexture(tblood3);
    }
    if(this->blood_hero==2){
        this->sblool.setTexture(tblood2);
    }
    if(this->blood_hero==1){
        this->sblool.setTexture(tblood1);
    }
    MyWindow::control()->window.draw(this->sblool);
}

