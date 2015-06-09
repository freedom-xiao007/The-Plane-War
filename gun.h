/*************************************************************************
	> File Name: Gun.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月07日 星期日 09时38分01秒
 ************************************************************************/

#ifndef _Gun_H
#define _Gun_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Gun
{
    public:
        Gun();
        static void fight(int type);
        static Gun* control();
        int cout_down;
    private:
        int order;
        static Gun* power;
};
#endif
