//
//  main.c
//  dailyCodingProblem177
//
//  Created by Denny Caruso on 28/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

/*
    This problem was asked by Airbnb.
    Given a linked list and a positive integer k, rotate the list to the right by k places.
    
    For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become 3 -> 5 -> 7 -> 7.
    Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4 -> 5 -> 1 -> 2.
 
 */

#include "header.h"

int main(int argc, const char * argv[]) {
    srand((unsigned int) time(NULL));
    
    ListPackage newListPackage;
    newListPackage.nNodes = generateIntegerNumber();
    newListPackage.nRotations = generateIntegerNumber();
    
    Node *root = createList(newListPackage.nNodes);
    printList(root, newListPackage.nNodes);
    
    newListPackage.root = root;
    Node *rotatedList = rotateList(newListPackage);
    printList(rotatedList, newListPackage.nNodes);
    
    return 0;
}
