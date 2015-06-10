/*************************************************************************
	> File Name: laser.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月10日 星期三 17时54分27秒
 ************************************************************************/

#ifndef _LASER_H
#define _LASER_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

class Enemy_one;
class Enemy_two;
class Laser
{
    public:
        Laser();
        static Laser* control();
        static void fight();
        void fire();
        void move();
        void check_cllision();
        void check_cllision(Enemy_one* heads);
        void check_cllision(Enemy_two* heads);
        int cout_down;
        bool is_fire;
    private:
        sf::Texture tlaser1;
        sf::Texture tlaser2;
        sf::Sprite slaser;
        sf::Texture texture;
        sf::Sprite sprite;
        static Laser* power;
};
#endif
