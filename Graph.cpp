/*
* Brent Li
* Assignment 7
* ASU ID: 1214890820
*/

#include <iostream>

#include "Graph.h"
#include "MinHeap.h"

//constructor
Graph::Graph(int nodes) {
    numNodes = nodes;
    currentSize = 0;
    graphArr = new LinkedList[numNodes];    //graphArr is an array of LinkedLists
}

//destructor
Graph::~Graph() {
    delete[] graphArr;
}

//add a node to the graph (creates new linked list)
void Graph::addNode(string name) {
    //create new node (root of new linked list)
    Node* proj = new Node;

    proj->projName = name;
    proj->dist = 0;
    proj->index = currentSize;

    //insert project at head of empty linked list
    graphArr[currentSize].insertProject(proj);
    currentSize++;
}

//adds an edge between two nodes (modifies src headed linked list), return true if successful, false if not
bool Graph::addEdge(string src, string dst, int dist) {
    //create destination node to be added
    Node* proj = new Node;
    proj->projName = dst;
    proj->dist = dist;

    for (int i = 0; i < numNodes; i++) {
        if (graphArr[i].getHeadName().compare(dst) == 0) {
            proj->index = graphArr[i].getHead()->index;
            break;
        }
    }

    //find corresponding linkedlist
    for (int i = 0; i < numNodes; i++) {
        if (graphArr[i].getHeadName().compare(src) == 0) { //if current linked list is target
            graphArr[i].insertProject(proj);    //insert project at tail
            return true;
        }
    }

    return false;
}

//prints the graph
void Graph::printGraph() {
    cout << "The Graph Content:" << endl << "-------------------" << endl;

    for (int i = 0; i < currentSize; i++) {
        graphArr[i].printLinkedList();
        cout << endl;
    }
}

//returns the index of the given project, return -1 if not found
int Graph::getIndex(string name) {
    for (int i = 0; i < numNodes; i++) {
        if (graphArr[i].getHeadName().compare(name) == 0) {
            return i;
        }
    }
    return -1;
}

//finds the shortest path using Dijkstra's Algorithm
void Graph::shortestPath(string src, string dst, bool isLength) {
    int srcIndex = getIndex(src);       //index of starting project
    int dstIndex = getIndex(dst);       //index of destination project
    int *d = new int[numNodes];         //create distance array
    string *pi = new string[numNodes];  //create pi array
    MinHeap minHeap = MinHeap(numNodes);    //create minheap object
    HeapNode u;             //used to keep track of the smallest node in the heap
    LinkedList linkedList;  //linked list object
    Node* temp = NULL;      //temp node used to traverse the linked list
    Node* adjList = NULL;
    
    for (int i = 0; i < numNodes; i++) {    //initialize d and pi array
        d[i] = INT32_MAX;
        pi[i] = "";
    }

    int rootIndex = getIndex(src);
    d[rootIndex] = 0;   //set distance of source to source to 0

    for (int i = 0; i < numNodes; i++) {    //add nodes into heap
        minHeap.addNode(i, graphArr[i].getHeadName(), d[i], graphArr[i].getHead()->index);
    }

    for (int i = (minHeap.getSize()) / 2; i >= 0; i--) {  //heapify the heap
        minHeap.heapify(i);
    }

    while (!minHeap.isEmpty()) {
        u = minHeap.extractMin();   //set u to smallest project in heap

        //graphArr[u] is adj list
        linkedList = graphArr[u.index];
        temp = linkedList.getHead()->next;

        while (temp != NULL) {
            unsigned int weight = d[u.index] + temp->dist;

            if ((unsigned int)d[temp->index] > weight && minHeap.find(temp->projName)) {
                d[temp->index] = d[u.index] + temp->dist;
                pi[temp->index] = u.projectName;
                minHeap.decreaseKey(temp->projName, d[temp->index]);
            }

            temp = temp->next;
        }
    }   
    
    //d and pi arrays are created, start pathtrace and handle outputs

    int index = 1;
    bool done = false;
    bool pathReachable = true;
    string* pathTrace = new string[numNodes];

    if (src.compare(dst) != 0) {      //when source is not destination
        //set destination node in path trace
        int traceIndex = getIndex(dst); //trace graphArr index
        pathTrace[0] = dst;

        if (pi[traceIndex].compare("") == 0) {  //destination unreachable
            done = true;
            pathReachable = false;
        }

        while (!done) { //while not done tracing back
            pathTrace[index] = pi[traceIndex];
            index++;
            
            if (pi[traceIndex].compare(src) == 0) {  //trace is complete
                done = true;
            }

            traceIndex = getIndex(pi[traceIndex]);

            if (index >= numNodes) {
                done = true;
                pathReachable = false;
            }
        }
    }

    if (!pathReachable) {
        cout << "Error: " << dst << " not reachable from " << src << endl;
        goto Exit;
    }

    if (isLength) { //print command is length
        cout << "LENGTH: " << d[dstIndex] << endl;
    }
    else {  //print command is path
        cout << "The shortest path:" << endl;

        if (src.compare(dst) == 0) {
            cout << src << endl;
            goto Exit;
        }

        if (index >= 1) {
            for (int i = index - 1; i >= 0; i--) {   //print path
                cout << pathTrace[i] << endl;
                if (i != 0) {
                    cout << "->" << endl;
                }
            }
        }
    }

Exit:
    //free memory, clean up
    delete [] d;
    delete [] pi;
    delete[] pathTrace;
}

//returns true if graph is full, false if not
bool Graph::graphIsValid() {
    if (currentSize == numNodes) {
        return true;
    }

    return false;
}