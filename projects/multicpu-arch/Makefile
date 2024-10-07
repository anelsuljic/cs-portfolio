OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cluster.o Pendientes.o Procesador.o Proceso.o
	g++ $(OPCIONS) -o program.exe program.o Cluster.o Pendientes.o Procesador.o Proceso.o

program.o: program.cc Proceso.hh Procesador.hh Pendientes.hh Cluster.hh BinTree.hh
	g++ $(OPCIONS) -c program.cc

Cluster.o: Cluster.cc Cluster.hh Proceso.hh Procesador.hh BinTree.hh
	g++ $(OPCIONS) -c Cluster.cc

Pendientes.o: Pendientes.cc Pendientes.hh Proceso.hh
	g++ $(OPCIONS) -c Pendientes.cc

Procesador.o: Procesador.cc Procesador.hh Proceso.hh
	g++ $(OPCIONS) -c Procesador.cc

Proceso.o: Proceso.cc Proceso.hh
	g++ $(OPCIONS) -c Proceso.cc

clean:
	rm *.o
	rm *.exe
	rm *.out

practica.tar: program.cc BinTree.hh Cluster.hh Cluster.cc Pendientes.hh Pendientes.cc Procesador.hh Procesador.cc Proceso.hh Proceso.cc Makefile html.zip
	tar -cvf practica.tar program.cc BinTree.hh Cluster.hh Cluster.cc Pendientes.hh Pendientes.cc Procesador.hh Procesador.cc Proceso.hh Proceso.cc Makefile html.zip