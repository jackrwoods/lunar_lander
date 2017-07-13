
/* Doubly-Linked List Implementation by Jack Woods */

#include "../include/LinkedList.h"


void initLinkedList(LinkedList* l) {
	l->current = (Link*) malloc(sizeof(Link));
	assert(l->current != NULL);
	l->size++;
	/* The sentinel, which denotes the beginning of the LL,
	   has its data initialized to NULL */
	l->current->next = NULL;
	l->current->prev = NULL;
	l->current->data = NULL;
}

LinkedList* newLinkedList() {
	LinkedList* l = (LinkedList*) malloc(sizeof(LinkedList));
	assert(l != NULL);
	initLinkedList(l);
	return l;
}

void freeLinkedList(LinkedList* l) {
	while (l->current->next != NULL) {
		Link* temp = l->current->next;
		free(l->current);
		l->current = temp;
	}
	free(current);
	l->current = NULL;
}

void deleteLinkedList(LinkedList* l) {
	freeLinkedList(l);
	free(l);
}
