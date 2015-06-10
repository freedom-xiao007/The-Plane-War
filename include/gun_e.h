/*************************************************************************
	> File Name: Gun_e.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 20时37分36秒
 ************************************************************************/

#ifndef _Gun_E_H
#define _Gun_E_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Enemy_two;
class Gun_e
{
    public:
        Gun_e();
        static void fight(int type, Enemy_two* enemy);
        static Gun_e* control();
        static int cout_down;
    private:
        int is_fire;
        static Gun_e* power;
};
#endif
