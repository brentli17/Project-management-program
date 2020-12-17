/*
* Brent Li
* Assignment 7
* ASU ID: 1214890820
*/

#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>

using namespace std;

struct Node {
    string projName;        //name of the project
    int dist;               //distance from the project to its head
    int index;              //index of the project
    struct Node* next;      //pointer to the next node
};

class LinkedList {
private:
    struct Node* head;      //head of the linked list
    int size;               //size of the linked list

public:
    LinkedList();                       //constructor
    void insertProject(Node* project);  //inserts a project at head if linked list is empty, or at tail if linked list is not empty
    string getHeadName();               //returns the name of the head of the list
    void printLinkedList();             //displays the contents of the linked list
    Node* getHead();                    //return head node
};

#endif