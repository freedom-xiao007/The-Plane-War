/*************************************************************************
	> File Name: state.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 15时16分56秒
 ************************************************************************/

#include<iostream>
#include"state.h"
#include"mywindow.h"

State::State()
{
    this->tstate.loadFromFile("state.png");
    this->sstate.setTexture(tstate);
    this->sstate.setPosition(300, 500);
}

void State::setstate()
{
    MyWindow::control()->window.draw(this->sstate);
}

