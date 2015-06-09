/*************************************************************************
	> File Name: state.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 15时14分34秒
 ************************************************************************/

#ifndef _STATE_H
#define _STATE_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

class State
{
    public:
        State();
        void setstate();
    private:
        sf::Texture tstate;
        sf::Sprite sstate;
};
#endif
