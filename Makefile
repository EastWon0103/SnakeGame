OBJECTS = main.o Board.o Snake.o SnakeGame.o ScoreBoard.o Mission.o Rank.o

all: SnakeGame

SnakeGame: $(OBJECTS)
	g++ -o SnakeGame obj/main.o obj/Board.o obj/Snake.o obj/SnakeGame.o obj/ScoreBoard.o obj/Mission.o obj/Rank.o -lncurses -std=c++14

main.o: src/main.cpp
	g++ -c -o obj/main.o src/main.cpp -std=c++14

SnakeGame.o: src/SnakeGame.cpp src/SnakeGame.h
	g++ -c -o obj/SnakeGame.o src/SnakeGame.cpp -std=c++14

Snake.o: src/Snake.cpp src/Snake.h
	g++ -c -o obj/Snake.o src/Snake.cpp -std=c++14

Board.o: src/Board.cpp src/Board.h
	g++ -c -o obj/Board.o src/Board.cpp -std=c++14
	
Mission.o: src/Mission.cpp src/Mission.h
	g++ -c -o obj/Mission.o src/Mission.cpp -std=c++14

ScoreBoard.o: src/ScoreBoard.cpp src/ScoreBoard.h
	g++ -c -o obj/ScoreBoard.o src/ScoreBoard.cpp -std=c++14

Rank.o: src/Rank.cpp src/Rank.h
	g++ -c -o obj/Rank.o src/Rank.cpp -std=c++14

run:
	./SnakeGame
	
clean: 
	rm obj/*.o