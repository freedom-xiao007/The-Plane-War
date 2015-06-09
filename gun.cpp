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

Gun* Gun::power = new Gun;

Gun* Gun::control()
{
    return power;
}
Gun::Gun()
{
    this->order=0;
    this->cout_down=0;
}
void Gun::fight(int type)
{
    if(type==11){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(Gun::control()->cout_down==5){
                if(Prop::weapon_level>1){
                Bullet_one_hero::create_bullet(-10);
                Bullet_one_hero::create_bullet(10);
                }
                if(Prop::weapon_level>0){
                Bullet_one_hero::create_bullet(5);
                Bullet_one_hero::create_bullet(-5);
                }
                Bullet_one_hero::create_bullet(0);
                Gun::control()->cout_down=0;
            }
            else{
                Gun::control()->cout_down++;
            }
        }
    }
    Bullet_one_hero::fight(1);
}
