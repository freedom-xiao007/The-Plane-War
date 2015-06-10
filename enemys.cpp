/*************************************************************************
    > File Name: Enemys.cpp
    > Author: lw
    > Mail: 1243925457@qq.com
    > Created Time: 2015年06月07日 星期日 09时39分59秒
 ************************************************************************/

#include"enemys.h"
#include"hero.h"
#include"enemy1.h"
#include"enemy2.h"
#include"boss1.h"
#include"kill_score.h"
#include"play.h"

Enemys* Enemys::power = new Enemys;

Enemys* Enemys::control()
{
    return power;
}

int Enemys::cout_down = 0;


Enemys::Enemys()
{
}

void Enemys::fight()
{
    if(Enemy_two::cout_down==(50/Play::speed)){
        Enemy_two::create_enemy();
        Enemy_two::cout_down=0;
    }
    else{
        ++Enemy_two::cout_down;
    }

    if(Enemy_one::cout_down==10/Play::speed){
        Enemy_one::create_enemy();
        Enemy_one::cout_down=0;
    }
    else{
        ++Enemy_one::cout_down;
    }

    Enemy_one::fight();
    Enemy_two::fight();
    if(Kill_score::k_score>1000){
        Boss1::fight();
        if(Boss1::control()->is_disppear==0){
        Boss1::control()->on=1;
        }
        if(Boss1::control()->blood<0){
            Play::level=2;
        }
    }
}

