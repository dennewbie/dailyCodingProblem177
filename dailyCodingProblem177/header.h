//
//  header.h
//  dailyCodingProblem177
//
//  Created by Denny Caruso on 28/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define newLine() { printf("\n\n\n"); }

#endif /* header_h */

enum bool { FALSE, TRUE };
typedef enum bool Bool;

struct info {
    int ID;
};

typedef struct info Data;

struct node {
    Data *nodeData;
    struct node *next;
};

typedef struct node Node;

Node *createList(unsigned short int);
Node *createNode(void);
void getErrorNodeCreation(void);
Data *createData(void);
void getData(Data *);
void getErrorDataCreation(void);
void printNode(Data *);
void printList(Node *, unsigned short int);
unsigned short int generateIntegerNumber(void);
