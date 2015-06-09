/*************************************************************************
	> File Name: scenario.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月05日 星期五 22时57分35秒
 ************************************************************************/

#ifndef _SCENARIO_H
#define _SCENARIO_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

class Map;
class Scenario
{
    public:
        Scenario();
        Map* map;
        void set_scenario();
        void adjust_interface();
        void interface();
        bool gamebegin;
        bool gameend;
    private:
};
#endif
