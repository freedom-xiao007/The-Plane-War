/*************************************************************************
	> File Name: bullet.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月07日 星期日 09时20分51秒
 ************************************************************************/

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Enemy_two;
class Bullet_one_enemy
{
    public:
        Bullet_one_enemy();
        void move();
        static void create_bullet(Enemy_two* enemys);
        static void show_bullet(Bullet_one_enemy* heads);
        static void clear_bullet();
        static void fight();
        static Bullet_one_enemy* control();
        static Bullet_one_enemy* create;
        static Bullet_one_enemy* head;
        static Bullet_one_enemy* link;
        Bullet_one_enemy* next;
        static int cout_down;
        void check_cllision();
        bool alive;
        static int is_fire;
    private:
        bool exist_son;
        bool on;
        float X;
        float Y;
        static Bullet_one_enemy* power;
        sf::Texture texture;
        sf::Sprite sprite;
};
