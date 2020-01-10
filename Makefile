CC=g++

CCFLAGS= -Wall -Werror -std=c++11 -g

LIBFLAGS=

SRC= $(wildcard *.cc)

OBJ= $(SRC:.cc=.o)


EXEC= main

all: $(EXEC)


$(EXEC): $(OBJ)

	$(CC) $(LIBFLAGS) $^ -o $@  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network


%.o: %.cc

	$(CC) $(CCFLAGS) -o $@ -c $<  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network



clean:

	rm -f $(OBJ) $(EXEC)
