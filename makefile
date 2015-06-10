s=main.o mywindow.o play.o map.o \
  scenario.o hero.o \
  enemy1.o enemys.o bullet_one_hero.o \
  gun.o enemy2.o bullet_one.enemy.o \
  blood_hero.o prop.o state.o \
  kill_score.o skill_score.o \
  boss1.o checkpoint.o laser.o


t=sfml-app

$(t):$(s)
	g++ $(s) -o $(t) -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-network

main.o:main.c
	g++ -c main.c

mywindow.o:mywindow.cpp mywindow.h
	g++ -c mywindow.cpp mywindow.h

play.o:play.h play.cpp
	g++ -c play.h play.cpp

map.o:map.h map.cpp
	g++ -c map.h map.cpp

scenario.o:scenario.h scenario.cpp
	g++ -c scenario.h scenario.cpp

hero.o:hero.h hero.cpp
	g++ -c hero.h hero.cpp

enemy1.o:enemy1.h enemy1.cpp
	g++ -c enemy1.h enemy1.cpp

enemys.o:enemys.h enemys.cpp
	g++ -c enemys.h enemys.cpp

bullet_one_hero.o:bullet_one_hero.h bullet_one_hero.cpp
	g++ -c bullet_one_hero.h bullet_one_hero.cpp

gun.o:gun.h gun.cpp
	g++ -c gun.h gun.cpp

enemy2.o:enemy2.h enemy2.cpp
	g++ -c enemy2.h enemy2.cpp

bullet_one_enemy.o:bullet_one_enemy.h bullet_one_enemy.cpp
	g++ -c bullet_one_enemy.cpp bullet_one_enemy.h

blood_hero.o:blood_hero.h blood_hero.cpp
	g++ -c blood_hero.h blood_hero.cpp

prop.o:prop.h prop.cpp 
	g++ -c prop.h prop.cpp

state.o:state.h state.cpp
	g++ -c state.h state.cpp

kill_score.o:kill_score.h kill_score.cpp
	g++ -c kill_score.h kill_score.cpp

skill_score.o:skill_score.h skill_score.cpp
	g++ -c skill_score.h skill_score.cpp

boss1.o:boss1.h boss1.cpp
	g++ -c boss1.h boss1.cpp

checkpoint.o:checkpoint.h checkpoint.cpp
	g++ -c checkpoint.h checkpoint.cpp

laser.o:laser.h laser.cpp 
	g++ -c laser.h laser.cpp
