//
// Created by nullbyte on 01/06/22.
//

#include <stdbool.h>
#include <stdlib.h>

#ifndef NODE_H
#define NODE_H

// -----------------------------------------------------------------------------
// Node structure definition
// -----------------------------------------------------------------------------

	// Normal Node => with next pointer
	struct Node {
			int value;
			struct Node *next;
	};

	// Double Node => with next and prev pointer
	struct dNode {
		int value;
		struct dNode *next;
		struct dNode *prev;
	};

#endif //NODE_H
