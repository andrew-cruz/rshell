FLAGS = -Wall -Werror -ansi -pedantic -std=c++11
COMP = g++

all:
	mkdir -p ./bin
	$(COMP) $(FLAGS) ./src/*.cpp -o ./bin/rshell

rshell:
	$(COMP) $(FLAGS) ./src/*.cpp -o ./bin/rshell

clean:
	rm -rf ./bin
