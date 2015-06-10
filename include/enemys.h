/*************************************************************************
	> File Name: Enemys.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月07日 星期日 09时38分01秒
 ************************************************************************/

#ifndef _Enemys_H
#define _Enemys_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Enemys
{
    public:
        Enemys();
        static Enemys* control();
        static void fight();
        static int cout_down;
    private:
        static Enemys* power;
};
#endif
