/*************************************************************************
	> File Name: prop.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 14时12分16秒
 ************************************************************************/

#include<iostream>
#include"prop.h"
#include"mywindow.h"
#include"skill_score.h"
#include"hero.h"

Prop* Prop::power = new Prop;

Prop* Prop::control()
{
    return power;
}

int Prop::weapon_level=0;

Prop::Prop()
{
    this->tweapon1.loadFromFile("weapon_upgrade.png");
    this->tweapon2.loadFromFile("weapon_upgrade1.png");
    this->sweapon.setTexture(tweapon2);
    this->sweapon.setPosition(300.0, 450.0);

    this->tfence1.loadFromFile("fence_cover.png");
    this->tfence2.loadFromFile("fence_cover1.png");
    this->sfence.setTexture(tfence2);
    this->sfence.setPosition(300.0, 400.0);

    this->tfence.loadFromFile("fence.png");
    this->fence_p.setTexture(tfence);

    this->can_fence=0;
    this->can_weapon=0;
    this->is_fence=0;
    this->fence_cout_down=0;
}

void Prop::setprop()
{
    this->fence();
    this->weapon();
    if(Skill_score::k_score>=10){
        this->can_fence=1;
    }
    else{
        this->can_fence=0;
    }
    if(this->can_fence==1){
        this->sfence.setTexture(tfence1);
    }
    if(this->can_weapon==1){
        this->sweapon.setTexture(tweapon1);
    }

    MyWindow::control()->window.draw(this->sfence);
    MyWindow::control()->window.draw(this->sweapon);
}

void Prop::fence()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
        if(Skill_score::k_score>10){
        this->is_fence=1;
        Skill_score::k_score-=10;
    }
    }

    if(this->is_fence==1){
        if(this->fence_cout_down==500){
            this->is_fence=0;
            this->fence_cout_down=0;
        }
        else{
            ++this->fence_cout_down;
        }
    }

    if(this->is_fence==1){
        this->fence_p.setPosition(Hero::control()->sprite.getPosition().x-10, Hero::control()->sprite.getPosition().y-10);
        MyWindow::control()->window.draw(this->fence_p);
    }
}

void Prop::weapon()
{
    if(Hero::control()->alive==0){
        Prop::weapon_level=0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
        if(Skill_score::k_score>=0){
            if(Prop::weapon_level<4){
                Prop::weapon_level+=1;
                Skill_score::k_score-=50;
            }
        }
    }

    if(Skill_score::k_score>50){
        this->can_weapon=1;
    }
    else{
        this->can_weapon=0;
    }
}
