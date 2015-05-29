#ifndef SCENARIO
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<sstream>
#include<stdlib.h>
#include<string>
#include<SFML/Audio.hpp>

class Playgame;

class Scenario
{
	 public:
			Scenario();
			void setmap();
			void setscore();
			void setmusic();
			static void adjustspeed();
			static void setscenario();
			static int level;
			static Scenario* comeit();
			static Scenario* it;
			static double grade;
			std::string strgrade;
			std::stringstream ssgrade;
			sf::Font gradefont;
			sf::Text gradetext;
			sf::Texture tmap;
			sf::Sprite smap;
			sf::Music backgroundmusic;
			static bool musicon;
			static float speed;
			static int adjust;
};

#endif
