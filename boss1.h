/*************************************************************************
	> File Name: boss1.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月10日 星期三 00时42分32秒
 ************************************************************************/

#ifndef _BOSS1_H
#define _BOSS1_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

class Boss1
{
    public:
        Boss1();
        static void fight();
        static Boss1* control();
        void move();
        void fire();
        int blood;        
    private:
        bool l_move;
        bool r_move;
        sf::Texture texture;
        sf::Sprite sprite;
        float X;
        float Y;
        static Boss1* power;
};
#endif
