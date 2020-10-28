MAIN = ../src/main.cpp
SRCS = ../src/*.cpp
INCS = ../include/*.hpp
OBJS = main.o grafo.o automata.o conjunto.o estado.o nodo.o transicion.o vaciadoP.o
EXEC = Vaciado_Pila
LIBS =

CC = g++
CFLAGS = -c -ansi -pedantic -Wno-deprecated -std=c++11
CDEBUG = -g

default: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)
$(OBJS): $(MAIN) $(SRCS) $(INCS)
	$(CC) $(CFLAGS) $(CDEBUG) $(MAIN) $(SRCS)

clean:
	rm -f $(OBJS) $(EXEC) core*.* *.*~ *~ *.h.gch
