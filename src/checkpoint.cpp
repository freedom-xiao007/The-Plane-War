/*************************************************************************
	> File Name: checkpoint.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月10日 星期三 17时15分29秒
 ************************************************************************/

#include<iostream>
#include"checkpoint.h"
#include"play.h"
#include"mywindow.h"
#include"boss1.h"
#include"kill_score.h"

Checkpoint* Checkpoint::power = new Checkpoint;

Checkpoint* Checkpoint::control()
{
    return power;
}

int Checkpoint::cout_down=0;

Checkpoint::Checkpoint()
{
    this->tcheckpoint1.loadFromFile("checkpoint1.png");
    this->tcheckpoint2.loadFromFile("checkpoint2.png");
    this->scheckpoint.setTexture(tcheckpoint1);
    this->pass=0;
}

void Checkpoint::setcheckpoint()
{
    if(Play::level==2&&Boss1::control()->blood==0){
        Checkpoint::control()->scheckpoint.setTexture(Checkpoint::control()->tcheckpoint2);
        Checkpoint::control()->pass=0;
        cout_down=0;
    }
    if(Checkpoint::control()->pass==0){
        if(cout_down<100){
            MyWindow::control()->window.draw(Checkpoint::control()->scheckpoint);
        cout_down++;
        }
        else{
            Checkpoint::control()->pass=1;
        }
    }
}
