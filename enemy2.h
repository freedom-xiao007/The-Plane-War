/*************************************************************************
	> File Name: enemy1.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 19时07分36秒
 ************************************************************************/

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>


class Enemy_two
{
    public:
        Enemy_two();
        void move();
        void fire();
        void dis_step(Enemy_two* enemy);
        sf::Sprite get_sprite();
        static void create_enemy();
        static void show_enemy(Enemy_two* heads);
        static void clear_enemy();
        static void fight();
        static Enemy_two* control();
        static Enemy_two* create;
        static Enemy_two* head;
        static Enemy_two* link;
        Enemy_two* next;
        static int cout_down;
        bool alive;
        bool exist_son;
        bool lmove;
        bool rmove;
        bool is_move;
        bool is_disppear;
        int dis_cout_down;
        int cout_down_b;
        int fire_cout_down;
    private:
        sf::Texture texture;
        sf::Sprite sprite;

        sf::Texture tdisppear;
        sf::Sprite disppear;
        float X;
        float Y;
        bool on;
        static Enemy_two* power;

        sf::SoundBuffer soudbuffer;
        sf::Sound sound;

};
