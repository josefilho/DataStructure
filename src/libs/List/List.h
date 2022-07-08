//-----------------------------------------------------------------------------
// Created by Jose C. S. F. on 01/06/22.
// Graduating in Computer Science at the State University of Mato Grosso do Sul (UEMS)
//-----------------------------------------------------------------------------
// Language: c
// This library is free software; you can redistribute it and/or
// modify it under the terms of the MIT license. See LICENSE for details.
// If you use this library, let me know via twitter: @lxblvk
//-----------------------------------------------------------------------------

#ifndef LIST_H
#define LIST_H

#include "../Node/Node.h"

// --------------------------------------------------
// Flags
// --------------------------------------------------

/*
 * Flag to indicate if the list is circular.
 * false: Not circular;
 * true: Circular.
*/
static bool CIRCULAR = false;

void setCircular ( bool circular );

bool isCircular ();

// --------------------------------------------------
// List functions
// --------------------------------------------------

/* Insertion */

/*
  insertionNodeInList:
  Inserts a new node in the list.

  @param node: The node contains the list.
  @param value: The value to be inserted into list.

  @return: True if the value was inserted; false otherwise.
*/
bool insertNodeInList ( struct Node**, int );

/*
  insertionDNodeInList:
  Inserts a new node in the list doubly chained.

  @param node: The node contains the list.
  @param value: The value to be inserted into list.

  @return: True if the value was inserted; false otherwise.
*/
bool insertDNodeInList ( struct dNode**, int );

/* Removing */

/*
  removeNodeFromList:
  Removes a node from the list.
  
  @param node: The node contains the list.
  @param value: The value to be removed from list.
  
  @return: True if the value was removed; false otherwise.
*/
bool removeNodeFromList ( struct Node**, int );

/*
  removeDNodeFromList:
  Removes a node from the list doubly chained.
  
  @param node: The node contains the list.
  @param value: The value to be removed from list.
  
  @return: True if the value was removed; false otherwise.
*/
bool removeDNodeFromList ( struct dNode**, int );

/*
  removeAllNodesFromList:
  Removes all nodes from the list.
  
  @param node: The node contains the list.
  
  @return: void.
*/
void removeAllNodesFromList ( struct Node** );

/*
  removeAllDNodesFromList:
  Removes all nodes from the list doubly chained.
  
  @param node: The node contains the list.
  
  @return: void.
*/
void removeAllDNodesFromList ( struct dNode** );

/* Searching */

/*
  searchNodeInList:
  Searches a node in the list.
  
  @param node: The node contains the list.
  @param value: The value to be searched in list.
  
  @return: void.
*/
bool searchNodeInList ( struct Node*, int );

/*
  searchDNodeInList:
  Searches a node in the list doubly chained.
  
  @param node: The node contains the list.
  @param value: The value to be searched in list.
  
  @return: void.
*/
bool searchDNodeInList ( struct dNode*, int );

/*
  findNodeInList:
  Finds a node in the list.

  @param node: The node contains the list.
  @param value: The value to be found in list.

  @return: The node found; NULL otherwise.
*/
struct Node* findNodeInList ( struct Node**, int );

/*
  findDNodeInList:
  Finds a node in the list doubly chained.
  
  @param node: The node contains the list.
  @param value: The value to be found in list.
  
  @return: The node found; NULL otherwise.
*/
struct dNode* findDNodeInList ( struct dNode**, int );

#endif //LIST_H
