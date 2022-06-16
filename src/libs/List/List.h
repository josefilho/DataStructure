//
// Created by nullbyte on 01/06/22.
//

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

void setCircular(bool circular);
bool isCircular();

// --------------------------------------------------
// List functions
// --------------------------------------------------

	/* Insertion */
	bool insertNodeInList(struct Node **, int);
	bool insertDNodeInList(struct dNode **, int);

	/* Removing */
	bool removeNodeFromList(struct Node **, int);
	bool removeDNodeFromList(struct dNode **, int);
	void removeAllNodesFromList(struct Node **);

	/* Searching */
	bool searchNodeInList(struct Node *, int);
	struct Node** findNodeInList(struct Node **, int);
	bool searchDNodeInList(struct dNode *, int);
	static struct dNode* findDNodeInList(struct dNode **, int);

#endif //LIST_H
