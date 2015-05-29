#include"enemy1.h"
#include"enemy.h"
#include"playgame.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<SFML/Graphics.hpp>
#include"bullet.h"
#include"ebullet.h"
#include"plane.h"
#include"scenario.h"


Enemy_one::Enemy_one()
{
	 if(!tenemy.loadFromFile("1enemy.png")){
			std::cout<<"ERWWWW"<<std::endl;
	 }
	 senemy.setTexture(tenemy);
}

Enemy_one* Enemy_one::create=new Enemy_one;

Enemy_one* Enemy_one::enemyhead=Enemy_one::create;

Enemy_one* Enemy_one::enemyline=Enemy_one::enemyhead;

Enemy_one* Enemy_one::come=Enemy_one::create;

Enemy_one* Enemy_one::comeit()
{
	 return come;
}


