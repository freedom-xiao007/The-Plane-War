/*************************************************************************
	> File Name: blood_hero.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 13时42分47秒
 ************************************************************************/

#ifndef _BLOOD_HERO_H
#define _BLOOD_HERO_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Blood_hero
{
    public:
        Blood_hero();
        void blood();
        static int blood_hero;
    private:
        sf::Texture tblood1;
        sf::Texture tblood2;
        sf::Texture tblood3;
        sf::Texture tblood4;
        sf::Sprite sblool;
};
#endif
