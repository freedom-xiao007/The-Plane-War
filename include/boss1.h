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
        ~Boss1();
        static Boss1* control();
        static void fight();
        void move();
        void fire();
        void dis_step();
        sf::Sprite get_sprite();
        int blood;        
        int disppear;
        bool is_disppear;
        bool on;
    private:
        int dis_cout_down;
        int fire_cout_down;
        bool alive;
        bool l_move;
        bool r_move;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::SoundBuffer soudbuffer;
        sf::Sound sound;
        float X;
        float Y;
        static Boss1* power;
};
#endif
