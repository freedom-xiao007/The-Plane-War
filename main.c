/*************************************************************************
	> File Name: main.c
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月05日 星期五 22时06分32秒
 ************************************************************************/
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>

#include"mywindow.h"
#include"play.h"
#include"bullet_one_hero.h"
#include"bullet_one.enemy.h"
#include"enemy1.h"
#include"enemy2.h"
#include"enemys.h"
#include"hero.h"
#include"map.h"
#include"scenario.h"
#include"gun.h"
#include"blood_hero.h"
#include"prop.h"
#include"state.h"
#include"kill_score.h"
#include"skill_score.h"
#include"boss1.h"
#include"checkpoint.h"
#include"laser.h"

int main()
{
    MyWindow::control()->window.setVerticalSyncEnabled(true);
    MyWindow::control()->window.setFramerateLimit(60);
    srand(time(0));
    while (MyWindow::control()->window.isOpen())
    {
        MyWindow::control()->interface_control();

        Play::control()->play();
    }
    return 0;
}
