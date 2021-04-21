dijkstra: main.o adjlist.o minheap.o
	g++ main.o adjlist.o minheap.o -std=c++11 -o dijkstra

main.o: main.cpp adjlist.h minheap.h
	g++ main.cpp adjlist.h minheap.h -c

adjlist.o: adjlist.cpp adjlist.h
	g++ adjlist.cpp adjlist.h -c

minheap.o: minheap.cpp minheap.h
	g++ minheap.cpp minheap.h -c

clean:
	rm main.o adjlist.o minheap.o