//-----------------------------------------------------------------------------
// Created by Jose C. S. F. on 01/06/22.
// Graduating in Computer Science at the State University of Mato Grosso do Sul (UEMS)
//-----------------------------------------------------------------------------
// Language: c
// This library is free software; you can redistribute it and/or
// modify it under the terms of the MIT license. See LICENSE for details.
// If you use this library, let me know via twitter: @lxblvk
//-----------------------------------------------------------------------------


#ifndef STACK_H
#define STACK_H

#include "../Node/Node.h"

/*
  pushStack:
  Pushes a new node to the stack.

  @param node: The node contains the stack.
  @param value: The value to be pushed into stack.

  @return: The node with the new value pushed.
*/
bool pushStack ( struct Node**, int );

/*
  popStack:
  Pops a node from the stack.

  @param node: The node contains the stack.
  
  @return: The value of the node popped, -1 if node popped doesn't exists or the
  Stack is empty.
*/
int popStack ( struct Node** );

#endif //STACK_H
