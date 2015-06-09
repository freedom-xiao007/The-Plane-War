/*************************************************************************
	> File Name: scenario.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月05日 星期五 23时03分42秒
 ************************************************************************/

#include<iostream>
#include"scenario.h"
#include"map.h"
#include"blood_hero.h"

Scenario::Scenario()
{
    this->map=new Map;
    this->gamebegin=0;
    this->gameend=0;
}

void Scenario::set_scenario()
{
    if(this->gamebegin==0){
        this->map->begin_interface();
    }
    if(this->gamebegin==1&&this->gameend==0){
        this->map->fight_interface();
    }
    if(this->gameend==1){
        this->map->end_interfece();
    }
}

void Scenario::adjust_interface()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this->gamebegin=1;
    }
    if(Blood_hero::blood_hero==0){
        this->gameend=1;
    }
    if(this->gameend==1){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            this->gameend=0;
            this->gamebegin=1;
        }
    }
}
 
void Scenario::interface()
{
    this->set_scenario();
    this->adjust_interface();
}
