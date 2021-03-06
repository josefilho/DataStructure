//-----------------------------------------------------------------------------
// Created by Jose C. S. F. on 01/06/22.
// Graduating in Computer Science at the State University of Mato Grosso do Sul (UEMS)
//-----------------------------------------------------------------------------
// Language: c
// This implementation library is free software; you can redistribute it and/or
// modify it under the terms of the MIT license. See LICENSE for details.
// If you use this library, let me know via twitter: @lxblvk
//-----------------------------------------------------------------------------

#include "List.h"

// SETTERS TO FLAGS
void setCircular ( bool circular ) {
	CIRCULAR = circular;
}

bool isCircular () {
	return CIRCULAR;
}

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
bool insertNodeInList ( struct Node** node, int value ) {
	if ( CIRCULAR ) {
		if ( *node == NULL ) { // If the list is empty
			*node = ( struct Node* ) malloc( sizeof( struct Node ) );
			if ( *node == NULL ) {
				return false;
			}
			( *node )->value = value;
			( *node )->next = *node;
		}
		else {
			if ( ( *node )->next == *node ) { // If the list have only one node
				if ( ( *node )->value < value ) {
					struct Node* newNode = ( struct Node* ) malloc( sizeof( struct Node ) );
					newNode->value = value;
					newNode->next = *node;
					( *node )->next = newNode;
				}
				else {
					struct Node* newNode = ( struct Node* ) malloc( sizeof( struct Node ) );
					newNode->value = value;
					newNode->next = *node;
					( *node )->next = newNode;
					*node = newNode;
				}
			}
			else { // If the list have more than one node
				if ( value < ( *node )->value ) { // If the value is smaller than the first node
					struct Node* newNode = ( struct Node* ) malloc( sizeof( struct Node ) );
					newNode->value = value;
					newNode->next = *node;

					struct Node* lastNode = *node;
					*node = newNode;
					while ( lastNode->next != ( *node )->next ) {
						lastNode = lastNode->next;
					}
					lastNode->next = *node;
				}
				else { // If the value is bigger than the first node
					struct Node* newNode = ( struct Node* ) malloc( sizeof( struct Node ) );
					newNode->value = value;

					struct Node* iterator = ( *node )->next;
					struct Node* temp = *node;
					while ( iterator->value < value && iterator != *node ) {
						temp = iterator;
						iterator = iterator->next;
					}
					temp->next = newNode;
					newNode->next = iterator;
				}
			}
		}
	}
	else {
		if ( *node == NULL ) { // If the list is empty
			*node = ( struct Node* ) malloc( sizeof( struct Node ) );
			if ( *node == NULL ) {
				return false;
			}
			( *node )->value = value;
			( *node )->next = NULL;
		}
		else {
			struct Node* newNode = NULL;
			if ( ( *node )->value >= value ) { // If the value is smaller than the first node
				newNode = ( struct Node* ) malloc( sizeof( struct Node ) );
				if ( newNode == NULL ) { return false; }
				newNode->value = value;
				newNode->next = *node;
				*node = newNode;
				return true;
			}
			if ( ( *node )->next == NULL ) { // if the list have one element
				newNode = ( struct Node* ) malloc( sizeof( struct Node ) );
				if ( newNode == NULL ) { return false; }
				newNode->value = value;
				newNode->next = NULL;
				( *node )->next = newNode;
				return true;
			}
			else { // If the list have more than one element
				struct Node* previous = *node;
				struct Node* iterator = *node;
				while ( iterator->value < value && iterator->next != NULL ) {
					previous = iterator;
					iterator = iterator->next;
				}
				if ( iterator->value < value ) {
					previous = iterator;
					iterator = NULL;
				}
				newNode = ( struct Node* ) malloc( sizeof( struct Node ) );
				if ( newNode == NULL ) { return false; }
				newNode->value = value;
				previous->next = newNode;
				newNode->next = iterator;

			}
		}
	}
	return true;
}

/*
  insertionDNodeInList:
  Inserts a new node in the list doubly chained.

  @param node: The node contains the list.
  @param value: The value to be inserted into list.

  @return: True if the value was inserted; false otherwise.
*/
bool insertDNodeInList ( struct dNode** head, int value ) {
	if ( *head == NULL ) {
		return false; // List without head
	}
	if ( ( *head )->next == NULL && ( *head )->prev == NULL ) { // If the list have no one element
		struct dNode* newNode = ( struct dNode* ) malloc( sizeof( struct dNode ) );
		if ( newNode == NULL ) {
			return false;
		}
		newNode->value = value;

		newNode->next = *head;
		newNode->prev = *head;
		( *head )->next = newNode;
		( *head )->prev = newNode;
	}
	else { // If the list have more than one node
		struct dNode* newNode = ( struct dNode* ) malloc( sizeof( struct dNode ) );
		if ( newNode == NULL ) {
			return false;
		}
		newNode->value = value;

		struct dNode* temp = ( *head )->prev;
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = *head;
		( *head )->prev = newNode;
	}
	return true;
}

/* Removing */

/*
  removeNodeFromList:
  Removes a node from the list.
  
  @param node: The node contains the list.
  @param value: The value to be removed from list.
  
  @return: True if the value was removed; false otherwise.
*/
bool removeNodeFromList ( struct Node** node, int value ) {
	if ( !searchNodeInList( *node, value ) ) { return false; }
	if ( CIRCULAR ) {
		if ( *node == NULL ) { // empty list
			return false;
		}
		else {
			if ( ( *node )->next == *node ) { // If the list have only one node
				struct Node* temp = *node;
				*node = NULL;
				free( temp );
				temp = NULL;
				return true;
			}
			if ( ( *node )->value == value ) { // first node
				struct Node* temp = *node;
				struct Node* lastNode = *node;
				while ( lastNode->next != *node ) {
					lastNode = lastNode->next;
				}
				*node = ( *node )->next;
				lastNode->next = *node;
				free( temp );
				temp = NULL;
				return true;
			}
			else { // not first node
				struct Node* previusNode = *node;
				struct Node* currentNode = *node;
				while ( currentNode->value != value ) {
					previusNode = currentNode;
					currentNode = currentNode->next;
				}
				previusNode->next = currentNode->next;
				free( currentNode );
				currentNode = NULL;
				return true;
			}
		}
	}
	else { // not circular
		if ( *node != NULL ) { // not empty list
			if ( ( *node )->next == NULL ) {// only one node
				struct Node* temp = *node;
				*node = NULL;
				free( temp );
				temp = NULL;
				return true;
			}
			if ( ( *node )->value == value ) { // first node
				struct Node* temp = *node;
				*node = ( *node )->next;
				free( temp );
				temp = NULL;
				return true;
			}
			else { // not first node
				struct Node* previusNode = *node;
				struct Node* currentNode = *node;
				while ( currentNode->value != value ) {
					previusNode = currentNode;
					currentNode = currentNode->next;
				}
				previusNode->next = currentNode->next;
				free( currentNode );
				currentNode = NULL;
				return true;
			}
		}
	}
	return false; // No exists the node
}

/*
  removeDNodeFromList:
  Removes a node from the list doubly chained.
  
  @param node: The node contains the list.
  @param value: The value to be removed from list.
  
  @return: True if the value was removed; false otherwise.
*/
bool removeDNodeFromList ( struct dNode** node, int value ) {
	if ( node == NULL || ( ( *node )->prev == NULL || ( *node )->next == NULL)) { return false; }
	struct dNode* nodeToRemove = findDNodeInList( node, value );
	if ( nodeToRemove == NULL ) { return false; }
	if ( nodeToRemove == ( *node )->next && nodeToRemove == ( *node )->prev ) { // If the node is the only node
		( *node )->next = NULL;
		( *node )->prev = NULL;
		free( nodeToRemove );
		nodeToRemove = NULL;
		return true;
	}
	struct dNode* previusNode = nodeToRemove->prev;
	struct dNode* nextNode = nodeToRemove->next;
	previusNode->next = nextNode;
	nextNode->prev = previusNode;
	free( nodeToRemove );
	nodeToRemove = NULL;
	return true;
}

/*
  removeAllNodesFromList:
  Removes all nodes from the list.
  
  @param node: The node contains the list.
  
  @return: void.
*/
void removeAllNodesFromList ( struct Node** node ) {
	if ( CIRCULAR ) {
		if ( *node != NULL ) {
			if ( ( *node )->next == *node ) {
				struct Node* temp = *node;
				*node = NULL;
				free( temp );
				temp = NULL;
			}
			else {
				struct Node* before = *node;
				struct Node* current = ( *node )->next;
				while ( current != *node ) {
					free( before );
					before = current;
					current = current->next;
				}
				free( before );
				before = NULL;
				*node = NULL;
			}
		}
	}
	else {
		if ( *node != NULL ) {
			struct Node* temp = *node;
			while ( *node != NULL ) {
				*node = ( *node )->next;
				free( temp );
				temp = *node;
			}
		}
		else {
			return;
		}
	}
}

/*
  removeAllDNodesFromList:
  Removes all nodes from the list doubly chained.
  
  @param node: The node contains the list.
  
  @return: void.
*/
void removeAllDNodesFromList ( struct dNode** head ) {
	if ( *head != NULL ) {
		if ( ( *head )->next == NULL || ( *head )->prev == NULL ){
			return;
		}
		struct dNode* node = ( *head )->next;
		while ( node != *head ) {
			struct dNode* temp = node;
			node = node->next;
			free( temp );
			temp = NULL;
		}
	}
}

/* Searching */

/*
  searchNodeInList:
  Searches a node in the list.
  
  @param node: The node contains the list.
  @param value: The value to be searched in list.
  
  @return: void.
*/
bool searchNodeInList ( struct Node* node, int value ) {
	struct Node* temp = node;
	if ( CIRCULAR ) {
		if ( node == NULL ) { return false; }
		if ( node->value == value ) { return true; }
		else { temp = node->next; }
		while ( temp != node ) {
			if ( temp->value == value ) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	else {
		while ( temp != NULL ) {
			if ( temp->value == value ) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
}

/*
  searchDNodeInList:
  Searches a node in the list doubly chained.
  
  @param node: The node contains the list.
  @param value: The value to be searched in list.
  
  @return: void.
*/
bool searchDNodeInList ( struct dNode* node, int value ) {
	if( node == NULL || node->next == NULL || node->prev == NULL ) { return false; }
	struct dNode* prev = node->prev;
	struct dNode* next = node->next;
	while ( prev != next && ( prev != node || next != node ) ) {
		if ( prev->value == value || next->value == value ) {
			return true;
		}
		prev = prev->prev;
		next = next->next;
	}
	if ( prev->value == value || next->value == value ) {
		return true;
	}
	return false;
}

/*
  findNodeInList:
  Finds a node in the list.

  @param node: The node contains the list.
  @param value: The value to be found in list.

  @return: The node found; NULL otherwise.
*/
struct Node* findNodeInList ( struct Node** list, int value ) {
	struct Node* temp = *list;
	if ( CIRCULAR ) {
		if ( temp == NULL ) { return NULL; }
		if ( temp->value == value ) { return temp; }
		else { temp = temp->next; }
		while ( temp != *list ) {
			if ( temp->value == value ) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
	else {
		while ( temp != NULL ) {
			if ( temp->value == value ) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
}

/*
  findDNodeInList:
  Finds a node in the list doubly chained.
  
  @param node: The node contains the list.
  @param value: The value to be found in list.
  
  @return: The node found; NULL otherwise.
*/
struct dNode* findDNodeInList ( struct dNode** head, int value ) {
	if ( *head == NULL ) { return NULL; } // empty list
	struct dNode* next = ( *head )->next;
	struct dNode* prev = ( *head )->prev;

	while ( prev != *head && next != *head ) {
		if ( prev->value == value || next->value == value ) {
			return prev->value == value ? prev : next;
		}
		prev = prev->prev;
		next = next->next;
	}

	return NULL; // not found
}
