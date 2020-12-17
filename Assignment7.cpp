/*
* Brent Li
* Assignment 7
* ASU ID: 1214890820
*/

#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>

#include "Graph.h"
#include "MinHeap.h"

using namespace std;

//read data from graphinfo.txt
bool fileRead(Graph** pGraph) {
    ifstream file;
    file.open("graphInfo.txt");
    string line, proj1, proj2;
    int numNodes, numEdges, dist;

    if (file.is_open()) {
        getline(file, line);   //get first line for num nodes and edges
        numNodes = stoi(line.substr(0, line.find_first_of(" "))); //parse and convert numNodes to int
        numEdges = stoi(line.substr(line.find_last_of(" ") + 1)); //parse and convert numEdges to int

        *pGraph = new Graph(numNodes);

        //handling for all nodes
        for (int i = 0; i < numNodes; i++) {
            getline(file, line);
            (*pGraph)->addNode(line);
        }

        //handling for all edges
        for (int i = 0; i < numEdges; i++) {
            getline(file, line);    //getline
            //parse first and second project as well as distance between them
            proj1 = line.substr(0, line.find_first_of(" "));
            proj2 = line.substr(line.find_first_of(" ") + 1, line.find_last_of(" ") - line.find_first_of(" ") - 1);
            dist = stoi(line.substr(line.find_last_of(" ") + 1));
            //add project
            (*pGraph)->addEdge(proj1, proj2, dist);
        }

        file.close();
        return (*pGraph)->graphIsValid();
    }

    return false;
}

// the main entrance of the program
int main() {
    bool stop = false, graphValid = false;
    string projects, srcProj, dstProj, input = "";
    Graph *pGraph = NULL;

    do{
        getline(cin, input);
        cout << "Next Command: " << input << endl;
        if (!graphValid && input.compare("fileread") != 0 && input.compare("quit") != 0) {  //graph is initialized and command isnt quit or fileread
            cout << "Error: graph not initialized" << endl;
        }
        else {  //graph is valid, handle command
            if (input.find(" ") != string::npos) {          //user entered "shortest"
                string printCommand;
                printCommand = input.substr(input.find_last_of(" ") + 1);   //get print command

                projects = input.substr(input.find_first_of(" ") + 1, input.find_last_of(" ") - input.find_first_of(" ") - 1);
                srcProj = projects.substr(0, projects.find(" "));
                dstProj = projects.substr(projects.find(" ") + 1);
                if (pGraph->getIndex(srcProj) == -1 || pGraph->getIndex(dstProj) == -1) { //one or more nodes are invalid
                    cout << "Error: one or more invalid nodes" << endl;
                    continue;
                }

                if (printCommand.compare("length") == 0) {  //print command is length, print length of shortest path from src to dst
                    pGraph->shortestPath(srcProj, dstProj, true);
                }
                else if (printCommand.compare("path") == 0) {   //print command is path, print shortest path from src to dst
                    pGraph->shortestPath(srcProj, dstProj, false);
                }
                else {  //invalid print command, such as "ok"
                    cout << "Error: unknown print command" << endl;
                }
            }
            else if (input.compare("fileread") == 0) {  //user entered command "fileread"
                delete pGraph;
                graphValid = fileRead(&pGraph);
            }
            else if (input.compare("print") == 0) {     //user entered command "print"
                pGraph->printGraph();
            }
            else if (input.compare("quit") == 0) {
                stop = true;
            }
        }
    } while (!stop);

    delete pGraph;
}