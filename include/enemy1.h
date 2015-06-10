/*************************************************************************
	> File Name: enemy1.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 19时07分36秒
 ************************************************************************/

#ifndef _ENEMY1_H
#define _ENEMY1_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>


class Enemy_one
{
    public:
        Enemy_one();
        void move();
        void dis_step(Enemy_one* enemy);
        sf::Sprite get_sprite();
        static void create_enemy();
        static void show_enemy(Enemy_one* heads);
        static void clear_enemy();
        static void fight();
        static Enemy_one* control();
        static Enemy_one* create;
        static Enemy_one* head;
        static Enemy_one* link;
        Enemy_one* next;
        static int cout_down;
        bool alive;
        bool exist_son;
        bool is_disppear;
        int dis_cout_down;
    private:
        sf::Texture texture;
        sf::Sprite sprite;

        sf::Texture tdisppear;
        sf::Sprite disppear;
        float X;
        float Y;
        bool on;
        static Enemy_one* power;

        sf::SoundBuffer soudbuffer;
        sf::Sound sound;
};
#endif
