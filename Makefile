CC=g++
CCFLAGS= -Wall -Werror -std=c++0x -g
#J'ai changé -std=c++11 en -std=c++0x Pour pouvoir utiliser la nouvelle norme C++ 2011
#On peut ainsi utiliser les fonctions anonymes et les fermetures
LIBFLAGS=
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

EXEC= main


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $^ -o $@ `pkg-config gtkmm-3.0 --cflags --libs`

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $< `pkg-config gtkmm-3.0 --cflags --libs`


clean:
	rm -f $(OBJ) $(EXEC)
