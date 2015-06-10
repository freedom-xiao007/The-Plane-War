/*************************************************************************
	> File Name: mywindow.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月05日 星期五 22时27分25秒
 ************************************************************************/

#include<iostream>
#include"mywindow.h"

MyWindow* MyWindow::power = new MyWindow;

MyWindow* MyWindow::control()
{
    return power;
}

MyWindow::MyWindow()
{
    window.create(sf::VideoMode(350, 530), "The-Plane-War");
}

MyWindow::~MyWindow()
{
    delete power;
}

void MyWindow::interface_control()
{
    sf::Event event;
    if (window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
    }
}
