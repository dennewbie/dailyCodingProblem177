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
    for(unsigned short int i = 0; i < nNodes; i++) {
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
    getData(newData);
    return newData;
}

void getData(Data *newData) {
    newData->ID = 1 + rand() % 100;
}

void getErrorDataCreation(void) {
    printf("\nError allocating memory for new data... Exit... \n");
    exit(EXIT_FAILURE);
}

void printNode(Data *data)  {
    printf("%10d\n", data->ID);
}

void printList(Node *root, unsigned short int nNodes) {
    for(unsigned short int i = 0; i < nNodes; i++) {
        printNode(root->nodeData);
        root = root->next;
    }
}

unsigned short int generateIntegerNumber() {
    return 1 + rand() % MAX_SIZE;
}
