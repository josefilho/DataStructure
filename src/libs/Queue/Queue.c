//-----------------------------------------------------------------------------
// Created by Jose C. S. F. on 01/06/22.
// Graduating in Computer Science at the State University of Mato Grosso do Sul (UEMS)
//-----------------------------------------------------------------------------
// Language: c
// This implementation library is free software; you can redistribute it and/or
// modify it under the terms of the MIT license. See LICENSE for details.
// If you use this library, let me know via twitter: @lxblvk
//-----------------------------------------------------------------------------

#include "Queue.h"

/*
  pushQueue:
  Pushes a new node to the queue.
  
  @param node: The node contains the queue.
  @param value: The value to be pushed into queue.
  
  @return: The node with the new value pushed.
*/
bool pushQueue ( struct Node** node, int value ) {
	if ( *node == NULL ) {
		*node = ( struct Node* ) malloc( sizeof( struct Node ) );
		if ( *node == NULL ) {
			return false;
		}
		( *node )->value = value;
		( *node )->next = NULL;
		return true;
	}
	else {
		struct Node* temp = *node;
		while ( temp->next != NULL ) {
			temp = temp->next;
		}
		temp->next = ( struct Node* ) malloc( sizeof( struct Node ) );
		if ( temp->next == NULL ) {
			return false;
		}
		temp->next->value = value;
		temp->next->next = NULL;
		return true;
	}
}

/*
  popQueue:
  Pops a node from the queue.
  
  @param node: The node contains the queue.
  
  @return: The value of the node popped.
*/
int popQueue ( struct Node** node ) {
	if ( *node == NULL ) {
		return -1;
	}
	if ( ( *node )->next == NULL ) {
		int value = ( *node )->value;
		free( *node );
		*node = NULL;
		return value;
	}
	else {
		struct Node* temp = *node;
		int value = temp->value;
		*node = ( *node )->next;
		free( temp );
		temp = NULL;
		return value;
	}
}
