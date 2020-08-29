//
//  header.c
//  dailyCodingProblem177
//
//  Created by Denny Caruso on 28/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

#include "header.h"

Node *createList(unsigned short int nNodes) {
    Node *head = createNode(), *current = head;
    for(unsigned short int i = 1; i < nNodes; i++) {
        current->next = createNode();
        current = current->next;
    }
    
    return head;
}

Node *createNode(void) {
    Node *newNode = (Node *) calloc(1, sizeof(Node));
    if(!newNode) getErrorNodeCreation();
    newNode->nodeData = createData();
    newNode->next = NULL;
    
    return newNode;
}

void getErrorNodeCreation(void) {
    printf("\nError allocating memory for new node... Exit... \n");
    exit(EXIT_FAILURE);
}

Data *createData(void) {
    Data *newData = (Data *) calloc(1, sizeof(Data));
    if(!newData) getErrorDataCreation();
    genData(newData);
    
    return newData;
}

void genData(Data *newData) {
    newData->ID = 1 + rand() % MAX_ID;
}

void getErrorDataCreation(void) {
    printf("\nError allocating memory for new data... Exit... \n");
    exit(EXIT_FAILURE);
}

void printNode(Data *data)  {
    printf("-> %5d\n", data->ID);
}

void printList(Node *root, unsigned short int nNodes) {
    newLine();
    printf("* This is the list created - Nodes: %d *\n\n", nNodes);
    while(root->next != NULL) {
        printNode(root->nodeData);
        root = root->next;
    }
    newLine();
}

unsigned short int generateIntegerNumber() {
    return 1 + rand() % MAX_SIZE;
}

Node *rotateList(ListPackage package) {
    printf("* nRotations: %d *", package.nRotations);
    Node *rotatedList, *current, *firstNode;
    rotatedList = current = package.root;
    
    unsigned short int lastListElementIndex = (package.nRotations % package.nNodes) - 1, i = 0;
    
    while(current->next != NULL && i < lastListElementIndex) {
        current = current->next;
        i++;
    }
    
    rotatedList = firstNode = current->next;
    current->next = NULL;
    while(rotatedList->next != NULL) rotatedList = rotatedList->next;
    rotatedList->next = package.root;
    
    return firstNode;
}
