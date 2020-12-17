/*
* Brent Li
* Assignment 7
* ASU ID: 1214890820
*/

#include "LinkedList.h"

//constructor
LinkedList::LinkedList() {
    head = NULL;
    size = 0;
}

//inserts a project at head if linked list is empty, or at tail if linked list is not empty
void LinkedList::insertProject(Node* project) {   //linked list is empty
    project->next = NULL;

    if (head == NULL) {
        head = project;
        size++;
    }
    else {  //linked list is not empty
        Node* last = head;

        while (last->next != NULL) {    //traverse to end of linked list
            last = last->next;
        }

        last->next = project;
        size++;
    }
}

//returns the name of the head of the list
string LinkedList::getHeadName() {
    return (head->projName);
}

//displays the contents of the linked list
void LinkedList::printLinkedList() {
    if (head != NULL) {
        cout << "From: " << head->projName << endl;
        if (head->next != NULL) {   //source project has links
            Node* temp = head->next;
            while (temp != NULL) {
                cout << "To: " << temp->projName << " with weight " << temp->dist << endl;
                temp = temp->next;
            }
        }
        else {  //source project has no links
            cout << "No adjacent nodes" << endl;
        }
    }
}

//return head node
Node* LinkedList::getHead() {
    return head;
}