/*************************************************************************
	> File Name: kill_score.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 15时36分39秒
 ************************************************************************/

#include<iostream>
#include"kill_score.h"
#include"mywindow.h"

Kill_score* Kill_score::power = new Kill_score;

Kill_score* Kill_score::control()
{
    return power;
}

int Kill_score::k_score = 0;

Kill_score::Kill_score()
{
    this->tscore.loadFromFile("kill_score.png");
    this->s_score.setTexture(tscore);
    this->s_score.setPosition(300, 0);
    this->tdoor.loadFromFile("score_door.png");
    this->sdoor.setTexture(tdoor);
    this->sdoor.setPosition(300, 0);
    if(this->fscore.loadFromFile("ziti.ttf")){
	 this->score.setFont(fscore);
	 }
    this->score.setPosition(310, 20);
	 this->score.setString(strgrade);
	 this->score.setCharacterSize(10);
	 this->score.setColor(sf::Color::Red);
}

void Kill_score::set_score()
{
    ssgrade << Kill_score::k_score;
    ssgrade >> strgrade;
    ssgrade.clear();
    score.setString(strgrade);
    MyWindow::control()->window.draw(score);
    MyWindow::control()->window.draw(s_score);
    MyWindow::control()->window.draw(sdoor);
}
