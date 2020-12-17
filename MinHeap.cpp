/*
* Brent Li
* Assignment 7
* ASU ID: 1214890820
*/

#include "MinHeap.h"

#include <stdio.h>
#include <stdlib.h>

//constructor
MinHeap::MinHeap(int size) {
    heapSize = size;
    heapArr = new HeapNode[size];
}

//destructor
MinHeap::~MinHeap() {
    delete [] heapArr;
}


//add a node into the heap array
void MinHeap::addNode(int pos, string name, int dist, int index) {
    //add project to heap array
    heapArr[pos].dist = dist;
    heapArr[pos].projectName = name;
    heapArr[pos].index = index;
}

//min heapify heap array
void MinHeap::heapify(int root) {
    int smallest, left, right;

    smallest = root;        //initialize smallest to root
    left = 2 * root + 1;    //find left child index
    right = 2 * root + 2;   //find right child index

    if (left < heapSize && heapArr[left].dist < heapArr[smallest].dist) {   //if left child is smaller than root
        smallest = left;
    }

    if (right < heapSize && heapArr[right].dist < heapArr[smallest].dist) { //if right child is smaller than smallest
        smallest = right;
    }

    if (smallest != root) { //smallest is not root
        //swap root and smallest
        HeapNode temp;
        temp = heapArr[root];
        heapArr[root] = heapArr[smallest];
        heapArr[smallest] = temp;

        //recursively heapify
        heapify(smallest);
    }
}

//create a min heap
void MinHeap::buildMinHeap(int size, string projNames[], int distances[]) {
    MinHeap minHeap(size);

    for (int i = 0; i < size; i++) {    //add all projects into heapArr (will not be min heap)
        addNode(i, projNames[i], distances[i], i);
    }

    heapify(0); //heapify the entire heap
}

//find the smallest node in the heap and delete it
HeapNode MinHeap::extractMin() {
    HeapNode smallestNode = heapArr[0];

    heapArr[0] = heapArr[heapSize - 1]; //delete min
    heapSize--;

    for (int i = (heapSize - 1) / 2; i >= 0; i--) {   //re-heapify
        heapify(i);
    }    
    
    return smallestNode;
}

//decrease a node's distance by dist amount, return true if successful, false if not
bool MinHeap::decreaseKey(string projName, int dist) {
    for (int i = 0; i < heapSize; i++) {
        if (heapArr[i].projectName.compare(projName) == 0) {    //desired project is found
            heapArr[i].dist = dist;    //decrease key
            for (int i = (heapSize - 1) / 2; i >= 0; i--) {   //re-heapify
                heapify(i);
            }
            return true;
        }
    }

    return false;
}

//return true if heap is empty, false if not
bool MinHeap::isEmpty() {
    if (heapSize == 0) {
        return true;
    }

    return false;
}

//return true if project with given name is found
bool MinHeap::find(string name) {
    for (int i = 0; i < heapSize; i++) {
        if (heapArr[i].projectName.compare(name) == 0) {
            return true;
        }
    }

    return false;
}

//returns size of the heap
int MinHeap::getSize() {
    return heapSize;
}