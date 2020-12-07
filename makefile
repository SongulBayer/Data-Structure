all: compile run

compile:
	g++ -I ./include/ -o ./bin/test ./src/test.cpp
run:
	./bin/test