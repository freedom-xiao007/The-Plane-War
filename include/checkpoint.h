/*************************************************************************
	> File Name: checkpoint.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月10日 星期三 17时10分53秒
 ************************************************************************/

#ifndef _CHECKPOINT_H
#define _CHECKPOINT_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

class Checkpoint
{
    public:
        Checkpoint();
        static void setcheckpoint();
        static Checkpoint* control();
    private:
        bool pass;
        static int cout_down;
        static Checkpoint* power;
        sf::Texture tcheckpoint1;
        sf::Texture tcheckpoint2;

        sf::Sprite scheckpoint;
};
#endif
