/*************************************************************************
	> File Name: play.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 10时27分18秒
 ************************************************************************/

#include<iostream>
#include"play.h"
#include"mywindow.h"
#include"enemys.h"
#include"hero.h"
#include"scenario.h"
#include"prop.h"

Play* Play::power = new Play;

Play* Play::control()
{
    return power;
}

Play::Play()
{

    this->scenario=new Scenario;
    this->music.openFromFile("she is my sin.wav");
    this->is_music=0;
}

Play::~Play()
{
    delete power;
}

void Play::play()
{
    MyWindow::control()->window.clear();
    this->scenario->interface();
    if(this->scenario->gamebegin==1&&this->scenario->gameend==0){
        Hero::control()->fight();
        Prop::control()->setprop();
        Enemys::fight();
        if(Play::control()->is_music==0){
            Play::control()->music.play();
            Play::control()->is_music=1;
        }
    }
    MyWindow::control()->window.display();
}
