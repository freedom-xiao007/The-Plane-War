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
    if(Enemy_two::cout_down==90){
        Enemy_two::create_enemy();
        Enemy_two::cout_down=0;
    }
    else{
        ++Enemy_two::cout_down;
    }

    if(Enemy_one::cout_down==20){
        Enemy_one::create_enemy();
        Enemy_one::cout_down=0;
    }
    else{
        ++Enemy_one::cout_down;
    }

    Enemy_one::fight();
    Enemy_two::fight();
    Boss1::fight();
}


