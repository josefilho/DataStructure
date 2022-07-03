//-----------------------------------------------------------------------------
// Created by Jose C. S. F. on 01/06/22.
// Graduating in Computer Science at the State University of Mato Grosso do Sul (UEMS)
//-----------------------------------------------------------------------------
// Language: c
// This library is free software; you can redistribute it and/or
// modify it under the terms of the MIT license. See LICENSE for details.
// If you use this library, let me know via twitter: @lxblvk
//-----------------------------------------------------------------------------

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
	struct Node* next;
};

// Double Node => with next and prev pointer
struct dNode {
	int value;
	struct dNode* next;
	struct dNode* prev;
};

#endif //NODE_H
