FLAGS = -Wall -Werror -ansi -pedantic
COMP = g++

all:
	mkdir -p ./bin
	$(COMP) $(FLAGS) ./src/main.cpp ./src/Command.cpp ./src/Shell.cpp ./src/And.cpp ./src/Or.cpp -o ./bin/rshell

rshell:
	$(COMP) $(FLAGS) ./src/main.cpp ./src/Command.cpp ./src/Shell.cpp ./src/And.cpp ./src/Or.cpp -o ./bin/rshell

clean:
	rm -rf ./bin
