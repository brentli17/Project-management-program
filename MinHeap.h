/*
* Brent Li
* Assignment 7
* ASU ID: 1214890820
*/
#pragma once
#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <string>

using namespace std;

//struct to represent each min heap node
struct HeapNode {
    string projectName;     //name of the project
    int dist;               //distance of the project from the source node
    int index;              //index of the project
};

class MinHeap {
private:
    int heapSize;           //size of the heap
    HeapNode* heapArr;      //heap array 

public:
    MinHeap(int size);
    ~MinHeap();
    void addNode(int pos, string name, int dist, int index); //add a node into the heap array
    void heapify(int root);                         //heapify the array into a min heap
    HeapNode extractMin();                          //return the smallest node
    bool decreaseKey(string projName, int key);     //decrease key for selected node, return true if successful, false if not
    bool isEmpty();                                 //return true if heap is empty, false if not
    bool find(string name);                         //return true if project with given name is found
    int getSize();                                  //return size of the heap
    void buildMinHeap(int size, string projNames[], int distances[]);   //create min heap
};

#endif