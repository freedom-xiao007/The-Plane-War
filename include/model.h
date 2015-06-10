/*************************************************************************
	> File Name: model.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月06日 星期六 13时09分11秒
 ************************************************************************/

#ifndef _MODEL_H
#define _MODEL_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<string.h>

class Model
{
    public:
        Model(std::string filename = "hero.png");
        void set_model(std::string filename);
        sf::Texture t_model;
        sf::Sprite s_model;
};
#endif
