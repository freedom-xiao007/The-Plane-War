/*************************************************************************
	> File Name: Gun_e.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 20时39分27秒
 ************************************************************************/

#include<iostream>
#include"gun_e.h"
#include"bullet_one_hero.h"
#include"bullet_one.enemy.h"
#include"hero.h"
#include"mywindow.h"

Gun_e* Gun_e::power = new Gun_e;

Gun_e* Gun_e::control()
{
    return power;
}

int Gun_e::cout_down=0;

Gun_e::Gun_e()
{
    this->is_fire=0;
}

void Gun_e::fight(int type, Enemy_two* enemy)
{
    if(type==21){
        Gun_e::control()->is_fire=rand() % 50;
        if(Gun_e::control()->is_fire==1){
            if(Gun_e::cout_down==5){
                Bullet_one_enemy::create_bullet(enemy);
                Gun_e::cout_down=0;
            }
            else{
                ++Gun_e::cout_down;
            }
        }
    }

    Bullet_one_enemy::fight();
}
