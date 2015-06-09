/*************************************************************************
	> File Name: boss1.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月10日 星期三 00时46分30秒
 ************************************************************************/

#include<iostream>
#include"boss1.h"
#include"mywindow.h"

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
    this->X=0;
    this->blood=50;
    this->l_move=0;
    this->r_move=0;
}

void Boss1::fight()
{
    Boss1::control()->move();
    Boss1::control()->fire();
}

void Boss1::move()
{
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
    MyWindow::control()->window.draw(this->sprite);
}

void Boss1::fire()
{
}
