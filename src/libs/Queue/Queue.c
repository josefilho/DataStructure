//
// Created by nullbyte on 01/06/22.
//

#include "Queue.h"

bool pushQueue(struct Node** node, int value) {
	if (*node == NULL) {
		*node = (struct Node*) malloc(sizeof(struct Node));
		if (*node == NULL) {
			return false;
		}
		(*node)->value = value;
		(*node)->next = NULL;
		return true;
	}
	else {
		struct Node* temp = *node;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = (struct Node*) malloc(sizeof(struct Node));
		if (temp->next == NULL) {
			return false;
		}
		temp->next->value = value;
		temp->next->next = NULL;
		return true;
	}
}

int popQueue(struct Node** node) {
	if (*node == NULL) {
		return -1;
	}
	if ((*node)->next == NULL) {
		int value = (*node)->value;
		free(*node);
		*node = NULL;
		return value;
	}
	else {
		struct Node* temp = *node;
		int value = temp->value;
		*node = (*node)->next;
		free(temp);
		temp = NULL;
		return value;
	}
}
