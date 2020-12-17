/*
* Brent Li
* Assignment 7
* ASU ID: 1214890820
*/
#pragma once
#ifndef GRAPH_H
#define GRAPH_H


#include <string>
#include "LinkedList.h"

using namespace std;

class Graph {
private:
    int numNodes;                   //number of nodes in the graph
    int currentSize;                //current number of nodes in the graph
    LinkedList* graphArr;           //linked list array to represent the graph

public:
    Graph(int numNodes);            //constructor
    ~Graph();                       //destructor

    void addNode(string name);      //add a node to the graph (creates new linked list)
    void printGraph();              //prints the graph
    bool graphIsValid();            //returns true if graph is full, false if not
    int getIndex(string name);      //returns the index of the given project, return -1 if not found
    bool addEdge(string src, string dst, int dist);             //adds an edge between two nodes (modifies src headed linked list), return true if successful, false if not
    void shortestPath(string src, string dst, bool isLength);   //finds the shortest path using Dijkstra's Algorithm
};

#endif
