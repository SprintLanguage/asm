
FLAGS = -Iincludes

SRC = $(wildcard src/*.c src/**/*.c src/**/**/*.c)
TESTS = $(wildcard tests/*.c)

test: 
	gcc $(FLAGS) $(SRC) $(TESTS) -o test.exe
