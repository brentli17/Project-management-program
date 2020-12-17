assignment7: Assignment7.o Graph.o LinkedList.o MinHeap.o
	g++ Assignment7.o Graph.o LinkedList.o MinHeap.o -o assignment7

Assignment7.o: Assignment7.cpp Graph.h LinkedList.h
Graph.o: Graph.cpp Graph.h LinkedList.h
LinkedList.o: LinkedList.cpp LinkedList.h
MinHeap.o: MinHeap.cpp MinHeap.h