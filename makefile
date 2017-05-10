FLAGS = -Wall -Werror -ansi -pedantic
COMP = g++

all:
	mkdir -p ./bin
	$(COMP) $(FLAGS) ./src/main.cpp ./src/Command.cpp ./src/Shell.cpp -o ./bin/exit.sh

rshell:
	$(COMP) $(FLAGS)  ./src/main.cpp  ./src/Command.cpp  ./src/Shell.cpp -o ./bin/exit.sh

clean:
	rm -rf ./bin
