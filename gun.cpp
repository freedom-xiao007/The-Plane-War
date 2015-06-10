/*************************************************************************
  > File Name: Gun.cpp
  > Author: lw
  > Mail: 1243925457@qq.com
  > Created Time: 2015年06月07日 星期日 09时39分59秒
 ************************************************************************/
#include"gun.h"
#include"bullet_one_hero.h"
#include"bullet_one.enemy.h"
#include"hero.h"
#include"mywindow.h"
#include"prop.h"
#include"laser.h"

Gun* Gun::power = new Gun;

Gun* Gun::control()
{
    return power;
}
Gun::Gun()
{
    this->cout_down=0;
}
void Gun::fight()
{
    Bullet_one_hero::fight();
    Bullet_one_enemy::fight();
    Laser::fight();
}
