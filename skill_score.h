/*************************************************************************
	> File Name: Skill_score.h
	> Author: lw
	> Mail: 1243925457@qq.com
	> Created Time: 2015年06月09日 星期二 16时25分16秒
 ************************************************************************/

#ifndef _Skill_score_H
#define _Skill_score_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<sstream>
#include<stdlib.h>
#include<string>

class Skill_score
{
    public:
        Skill_score();
        static Skill_score* control();
        void set_score();
        static int k_score;
    private:
        sf::Texture tscore;
        sf::Sprite s_score;
        sf::Texture tdoor;
        sf::Sprite sdoor;
        sf::Font fscore;
        sf::Text score;
        std::string strgrade;
        std::stringstream ssgrade;
        static Skill_score* power;
};

#endif
