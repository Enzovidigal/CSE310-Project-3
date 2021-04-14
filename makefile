dijkstra: main.o hash.o
	g++ main.o hash.o -std=c++11 -o dijkstra

main.o: main.cpp defn.h
	g++ main.cpp -c

hash.o: hash.cc defn.h
	g++ hash.cc defn.h -c

clean:
	rm main.o hash.o