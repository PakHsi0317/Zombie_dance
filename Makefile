exe: hw5_Jiao_Baixi.o zombie_Jiao.o
	g++ -Wall -g hw5_Jiao_Baixi.o zombie_Jiao.o -o exe

hw5_Jiao_Baixi.o: hw5_Jiao_Baixi.cpp linkedlist_Jiao.hpp
	g++ -Wall -c hw5_Jiao_Baixi.cpp

zombie_Jiao.o: zombie_Jiao.cpp
	g++ -Wall -c zombie_Jiao.cpp

clean:
	\rm *.o *~ <exe>