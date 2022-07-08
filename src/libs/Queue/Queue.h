//-----------------------------------------------------------------------------
// Created by Jose C. S. F. on 01/06/22.
// Graduating in Computer Science at the State University of Mato Grosso do Sul (UEMS)
//-----------------------------------------------------------------------------
// Language: c
// This library is free software; you can redistribute it and/or
// modify it under the terms of the MIT license. See LICENSE for details.
// If you use this library, let me know via twitter: @lxblvk
//-----------------------------------------------------------------------------

#ifndef QUEUE_H
#define QUEUE_H

#include "../Node/Node.h"

/*
  pushQueue:
  Pushes a new node to the queue.
  
  @param node: The node contains the queue.
  @param value: The value to be pushed into queue.
  
  @return: The node with the new value pushed.
*/
bool pushQueue ( struct Node**, int );

/*
  popQueue:
  Pops a node from the queue.
  
  @param node: The node contains the queue.
  
  @return: The value of the node popped.
*/
int popQueue ( struct Node** );

#endif //QUEUE_H
