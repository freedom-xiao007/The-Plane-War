/*************************************************************************
	> File Name: hero.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 11时56分12秒
 ************************************************************************/

#ifndef _HERO_H
#define _HERO_H
#include<string.h>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Hero
{
    public:
        Hero();
        static Hero* control();
        void fight();
        void move();
        void fire();
        void lfly();
        void rfly();
        void ufly();
        void dfly();
        sf::Texture texture;
        sf::Sprite sprite;
        float X;
        float Y;
        bool alive;
        int level;
    private:
        static Hero* power;
};
#endif
