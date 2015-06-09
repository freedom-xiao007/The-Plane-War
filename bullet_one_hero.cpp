/*************************************************************************
	> File Name: bullet_one.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月07日 星期日 09时27分48秒
 ************************************************************************/

#include"bullet_one_hero.h"
#include"mywindow.h"
#include"enemy1.h"
#include"hero.h"
#include"enemy2.h"
#include"skill_score.h"
#include"kill_score.h"

Bullet_one_hero* Bullet_one_hero::power = new Bullet_one_hero;

Bullet_one_hero* Bullet_one_hero::control()
{
    return power;
}

Bullet_one_hero* Bullet_one_hero::create = Bullet_one_hero::power;

Bullet_one_hero* Bullet_one_hero::head = Bullet_one_hero::power;

Bullet_one_hero* Bullet_one_hero::link = Bullet_one_hero::head;

int Bullet_one_hero::cout_down = 0;

Bullet_one_hero::Bullet_one_hero()
{
    if(this->texture.loadFromFile("bullet1_hero.png")){
        this->sprite.setTexture(this->texture);
    }
    if(this->soudbuffer.loadFromFile("shoot_sound1.wav")){
        this->sound.setBuffer(soudbuffer);
    }
    this->exist_son=0;
    this->on=0;
    this->alive=1;

}

void Bullet_one_hero::move()
{
    MyWindow::control()->window.draw(this->sprite);
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->sprite.move(0.0, -5.0);
        this->Y-=5;
    }
}

void Bullet_one_hero::fight(int a)
{
    Bullet_one_hero::clear_bullet();
    Bullet_one_hero::show_bullet(Bullet_one_hero::head);
}

void Bullet_one_hero::create_bullet(int b)
{
    Bullet_one_hero::create->sound.play();
    Bullet_one_hero::create->next = new Bullet_one_hero;
    Bullet_one_hero::create->X=Hero::control()->sprite.getPosition().x;
    Bullet_one_hero::create->Y=Hero::control()->sprite.getPosition().y;
    Bullet_one_hero::create->sprite.setPosition(Bullet_one_hero::create->X+14+b, Bullet_one_hero::create->Y);
    Bullet_one_hero::create->exist_son=1;
    Bullet_one_hero::create->on=1;
    Bullet_one_hero::create=Bullet_one_hero::create->next;
}

void Bullet_one_hero::show_bullet(Bullet_one_hero* heads)
{
    if(heads->on==1){
        if(heads->alive==1){
            heads->move();
            heads->check_cllision(Enemy_one::head);
            heads->check_cllision(Enemy_two::head);
        }
        if(heads->exist_son==1){
            Bullet_one_hero::show_bullet(heads->next);
        }
    }
}

void Bullet_one_hero::clear_bullet()
{
    if(Bullet_one_hero::head->on==1){
        if(Bullet_one_hero::head->Y<0||Bullet_one_hero::head->alive==0){
            Bullet_one_hero::link=Bullet_one_hero::head;
            Bullet_one_hero::head=Bullet_one_hero::head->next;
            delete Bullet_one_hero::link;
        }
    }
}

void Bullet_one_hero::check_cllision(Enemy_one* heads)
{
    if(heads->alive==1&&this->sprite.getGlobalBounds().intersects(heads->get_sprite().getGlobalBounds())&&head->alive==1&&this->alive==1){
        this->alive=0;
        heads->alive=0;
        Kill_score::k_score+=10;
        Skill_score::k_score+=1;
    }
    else{
        if(heads->exist_son==1){
            this->check_cllision(heads->next);
        }
    }
}

void Bullet_one_hero::check_cllision(Enemy_two* heads)
{
    if(heads->alive==1&&this->sprite.getGlobalBounds().intersects(heads->get_sprite().getGlobalBounds())&&head->alive==1&&this->alive==1){
        this->alive=0;
        heads->alive=0;
        Kill_score::k_score+=10;
        Skill_score::k_score+=1;
    }
    else{
        if(heads->exist_son==1){
            this->check_cllision(heads->next);
        }
    }
}
