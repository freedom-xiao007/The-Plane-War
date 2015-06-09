/*************************************************************************
	> File Name: play.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 10时20分53秒
 ************************************************************************/

#ifndef _PLAY_H
#define _PLAY_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Scenario;
class Play
{
    public:
        Play();
        ~Play();
        void play();
        static Play* control();
        Scenario* scenario;
    private:
        bool is_music;
        static Play* power;
        sf::Music music;
};
#endif
