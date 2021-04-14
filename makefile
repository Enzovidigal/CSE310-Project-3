dijkstra: main.o adjlist.o
	g++ main.o adjlist.o -std=c++11 -o dijkstra

main.o: main.cpp defn.h adjlist.h
	g++ main.cpp -c

adjlist.o: adjlist.cpp defn.h adjlist.h
	g++ adjlist.cpp defn.h adjlist.h -c

clean:
	rm main.o adjlist.o