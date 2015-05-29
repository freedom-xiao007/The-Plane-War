all=main.o playgame.o plane.o enemy.o bullet.o ebullet.o


g=g++
t=sfml-app
$(t):$(all)
	$(g) $(all) -o $(t) -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system 


main.o:main.c playgame.h plane.h bullet.h enemy.h
	g++ -c main.c playgame.h plane.h bullet.h enemy.h

playgame.o:playgame.h playgame.cpp
	g++ -c playgame.h playgame.cpp

plane.o:plane.cpp plane.h
	g++ -c plane.cpp plane.h

enemy.o:enemy.cpp enemy.h playgame.h
	g++ -c enemy.cpp enemy.h playgame.h

bullet.o:bullet.cpp bullet.h playgame.h plane.h
	g++ -c bullet.cpp bullet.h playgame.h plane.h

ebullet.o:ebullet.cpp ebullet.h
	g++ -c ebullet.cpp ebullet.h

clear:
	rm *.o
