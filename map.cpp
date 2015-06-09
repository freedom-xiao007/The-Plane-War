/*************************************************************************
	> File Name: map.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 09时40分54秒
 ************************************************************************/

#include"map.h"
#include"mywindow.h"
#include"blood_hero.h"
#include"prop.h"
#include"state.h"
#include"kill_score.h"
#include"skill_score.h"

Map::Map()
{
    if(this->t_begin1.loadFromFile("t_begin1.jpg")){
        this->s_begin1.setTexture(t_begin1);
    }
    if(this->t_begin2.loadFromFile("t_begin2.png")){
        this->s_begin2.setTexture(t_begin2);
    }
    if(this->t_fight1.loadFromFile("t_fight1.jpg")){
        this->s_fight1.setTexture(t_fight1);
    }
    if(this->t_end1.loadFromFile("end1.jpg")){
        this->s_end1.setTexture(t_end1);
    }
    if(this->t_end2.loadFromFile("end.png")){
        this->s_end2.setTexture(t_end2);
    }

    this->blood_h = new Blood_hero;
    this->state = new State;
}

void Map::begin_interface()
{
    MyWindow::control()->window.draw(this->s_begin1);
    MyWindow::control()->window.draw(this->s_begin2);
}

void Map::fight_interface()
{
    MyWindow::control()->window.draw(this->s_fight1);
    this->blood_h->blood();
    this->state->setstate();
    Kill_score::control()->set_score();
    Skill_score::control()->set_score();
}

void Map::end_interfece()
{
    MyWindow::control()->window.draw(s_end1);
    MyWindow::control()->window.draw(s_end2);
}

