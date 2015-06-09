/*************************************************************************
	> File Name: bullet.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月07日 星期日 09时20分51秒
 ************************************************************************/

#ifndef _BULLET_H
#define _BULLET_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Enemy_one;
class Enemy_two;
class Bullet_one_hero
{
    public:
        Bullet_one_hero();
        void move();
        static void create_bullet(int b);
        static void show_bullet(Bullet_one_hero* heads);
        static void clear_bullet();
        static void fight(int a);
        static Bullet_one_hero* control();
        static Bullet_one_hero* create;
        static Bullet_one_hero* head;
        static Bullet_one_hero* link;
        Bullet_one_hero* next;
        static int cout_down;
        void check_cllision(Enemy_one* heads);
        void check_cllision(Enemy_two* heads);
        bool alive;
    private:
        bool exist_son;
        bool on;
        float X;
        float Y;
        static Bullet_one_hero* power;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::SoundBuffer soudbuffer;
        sf::Sound sound;
};
#endif
