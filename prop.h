/*************************************************************************
	> File Name: prop.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 14时06分17秒
 ************************************************************************/

#ifndef _PROP_H
#define _PROP_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Prop
{
    public:
        Prop();
        static Prop* control();
        void setprop();
        void fence();
        void weapon();
        bool can_weapon;
        bool can_fence;
        static int weapon_level;
    private:
        int fence_cout_down;
        static Prop* power;
        bool is_fence;
        sf::Texture tweapon1;
        sf::Texture tweapon2;
        sf::Sprite sweapon;

        sf::Texture tfence1;
        sf::Texture tfence2;
        sf::Sprite sfence;

        sf::Texture tfence;
        sf::Sprite fence_p;
};
#endif
