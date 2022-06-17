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
bool insertNodeInList ( struct Node**, int );

bool insertDNodeInList ( struct dNode**, int );

/* Removing */
bool removeNodeFromList ( struct Node**, int );

bool removeDNodeFromList ( struct dNode**, int );

void removeAllNodesFromList ( struct Node** );

void removeAllDNodesFromList ( struct dNode** );

/* Searching */
bool searchNodeInList ( struct Node*, int );

bool searchDNodeInList ( struct dNode*, int );

static struct dNode* findDNodeInList ( struct dNode**, int );

#endif //LIST_H
