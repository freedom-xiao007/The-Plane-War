/*************************************************************************
	> File Name: map.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 07时49分27秒
 ************************************************************************/

#ifndef _MAP_H
#define _MAP_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Blood_hero;
class State;
class Map
{
    public:
        Map();
        void begin_interface();
        void end_interfece();
        void fight_interface();
        Blood_hero* blood_h;
        State* state;
    private:
        sf::Texture t_begin1;
        sf::Sprite s_begin1;

        sf::Texture t_begin2;
        sf::Sprite s_begin2;

        sf::Texture t_fight1;
        sf::Sprite s_fight1;

        sf::Texture t_end1;
        sf::Sprite s_end1;

        sf::Texture t_end2;
        sf::Sprite s_end2;
};
#endif
