/*************************************************************************
	> File Name: bullet_one.cpp
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月07日 星期日 09时27分48秒
 ************************************************************************/

#include"bullet_one.enemy.h"
#include"mywindow.h"
#include"hero.h"
#include"enemy2.h"

Bullet_one_enemy* Bullet_one_enemy::power = new Bullet_one_enemy;

Bullet_one_enemy* Bullet_one_enemy::control()
{
    return power;
}

Bullet_one_enemy* Bullet_one_enemy::create = Bullet_one_enemy::power;

Bullet_one_enemy* Bullet_one_enemy::head = Bullet_one_enemy::power;

Bullet_one_enemy* Bullet_one_enemy::link = Bullet_one_enemy::head;

int Bullet_one_enemy::cout_down = 0;

int Bullet_one_enemy::is_fire = 0;

Bullet_one_enemy::Bullet_one_enemy()
{
    if(this->texture.loadFromFile("bullet1_enemy.png")){
        this->sprite.setTexture(this->texture);
    }
        this->exist_son=0;
    this->on=0;
    this->alive=1;
}

void Bullet_one_enemy::move()
{
    MyWindow::control()->window.draw(this->sprite);
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->sprite.move(0.0, 0.5);
        this->Y+=0.5;
    }
}

void Bullet_one_enemy::fight()
{
    Bullet_one_enemy::clear_bullet();
    Bullet_one_enemy::show_bullet(Bullet_one_enemy::head);
}

void Bullet_one_enemy::create_bullet(Enemy_two* enemys)
{
    Bullet_one_enemy::create->next = new Bullet_one_enemy;
    Bullet_one_enemy::create->X=enemys->get_sprite().getPosition().x;
    Bullet_one_enemy::create->Y=enemys->get_sprite().getPosition().y;
    Bullet_one_enemy::create->sprite.setPosition(enemys->get_sprite().getPosition());

    Bullet_one_enemy::create->exist_son=1;
    Bullet_one_enemy::create->on=1;
    Bullet_one_enemy::create=Bullet_one_enemy::create->next;
}

void Bullet_one_enemy::show_bullet(Bullet_one_enemy* heads)
{
    if(heads->on==1){
        if(heads->alive==1){
            heads->move();
            heads->check_cllision();
        }
        if(heads->exist_son==1){
            Bullet_one_enemy::show_bullet(heads->next);
        }
    }
}

void Bullet_one_enemy::clear_bullet()
{
    if(Bullet_one_enemy::head->on==1){
        if(Bullet_one_enemy::head->Y>500||Bullet_one_enemy::head->alive==0){
            Bullet_one_enemy::link=Bullet_one_enemy::head;
            Bullet_one_enemy::head=Bullet_one_enemy::head->next;
            delete Bullet_one_enemy::link;
        }
    }
}

void Bullet_one_enemy::check_cllision()
{
    if(this->sprite.getGlobalBounds().intersects(Hero::control()->sprite.getGlobalBounds())&&head->alive==1&&this->alive==1){
        this->alive=0;
        Hero::control()->alive=0;
    }
}
