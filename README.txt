===========================================================================================================================================================
Assignment7.cpp:
	fileRead():
		Reads info from graphInfo.txt, then adds all nodes and edges into the graph.
		
	main():
		Takes inputs from the user. Every command the user enters is printed back out using the following format: Next command: <user's command>.
		Possible commands: 
			-fileread
			-print
			-quit
			-shortest <source> <destination> <printCommand>
===========================================================================================================================================================
Graph.h:
	This is the header file for Graph.cpp, contains the Graph class,more information about its functions below
===========================================================================================================================================================
Graph.cpp:
	Graph(int nodes):
		Constructor, intializes numNodes, currentSize, and graphArr
	
	addNode(string name):
		Adds a node to the graph, each node added here is the head to a linked list

	addEdege(string src, string dst, int dist):
		Adds a node to the linkedlist corresponding to the src node

	printGraph():
		Prints the graph to the user

	getIndex(string name):
		Takes a name of a project as an input, and returns its index within the graph

	shortestPath(string src, string dst, bool isLength):
		Uses Dijkstra's Algorithm to find the shortest path from src to dst, then either prints the shortest path or prints the length of the 
		shortest path. If dst is not reachable from src, no path/distance will be outputed

	graphIsValid():
		Returns true if the graph is empty, false if it is not
===========================================================================================================================================================
MinHeap.h:
	This is the header file for MinHeap.cpp, contains the MinHeap class and HeapNode struct, more information about its functions below
===========================================================================================================================================================
MinHeap.cpp:
	MinHeap(int size):
		Constructor, intializes heapSize, currentSize, and heapArr

	addNode(int pos, string name, int dist, int index):
		Adds a node with the given data into heapArr, may not maintain min heap property

	heapify(int root):
		Used to maintain min heap property, used in a loop from bottom to top
	
	buildMinHeap(int size, string projNames[], int distances[]):
		Used to create a min heap given a list of projects **not used**

	extractMin():
		Finds, removes, then returns the project closest to the source project, will maintain min heap property

	decreaseKey(string projName, int dist):
		Finds the given project, and sets its distance value to dist, will maintain min heap property

	isEmpty():
		Returns true if the heap is empty, false if it is not
	
	find(string name):
		Returns true if the given project is found in the heap, false if it is not

	getSize():
		returns the size of the heap
===========================================================================================================================================================
LinkedList.h:
	This is the header file for LinkedList.cpp, contains the LinkedList class and Node struct, more information about its functions below
===========================================================================================================================================================
LinkedList.cpp:
	LinkedList():
		Constructor, initializes head to NULL, and sets size to 0
	
	insertProject(Node* project):
		Finds the first availble spot in the linked list and places the given project there

	getHeadName():
		Returns the name of the head of the linked list

	printLinkedList():
		Helper function for print command, displays the linked list

	getHead():
		Returns the head node		
===========================================================================================================================================================