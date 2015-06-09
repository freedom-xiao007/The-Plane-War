/*************************************************************************
	> File Name: Skill_score.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 16时29分07秒
 ************************************************************************/

#include<iostream>
#include"skill_score.h"
#include"mywindow.h"

Skill_score* Skill_score::power = new Skill_score;

Skill_score* Skill_score::control()
{
    return power;
}

int Skill_score::k_score = 0;

Skill_score::Skill_score()
{
    this->tscore.loadFromFile("skill_score.png");
    this->s_score.setTexture(tscore);
    this->s_score.setPosition(300, 50);
    this->tdoor.loadFromFile("score_door.png");
    this->sdoor.setTexture(tdoor);
    this->sdoor.setPosition(300, 50);
    if(this->fscore.loadFromFile("ziti.ttf")){
	 this->score.setFont(fscore);
	 }
    this->score.setPosition(310, 80);
	 this->score.setString(strgrade);
	 this->score.setCharacterSize(10);
	 this->score.setColor(sf::Color::Blue);
}

void Skill_score::set_score()
{
    ssgrade << Skill_score::k_score;
    ssgrade >> strgrade;
    ssgrade.clear();
    score.setString(strgrade);
    MyWindow::control()->window.draw(score);
    MyWindow::control()->window.draw(s_score);
    MyWindow::control()->window.draw(sdoor);
}
