/*************************************************************************
	> File Name: mywindow.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月05日 星期五 22时23分54秒
 ************************************************************************/

#ifndef _MYWINDOW_H
#define _MYWINDOW_H
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class MyWindow
{
    public:
        MyWindow();
        ~MyWindow();
        static MyWindow* control();
        void interface_control();
        sf::RenderWindow window;
    private:
        static MyWindow* power;
};
#endif
