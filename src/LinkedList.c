
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

void _freeLink(Link* li) {
	assert(li != NULL);
	Link* temp = li;
	li->prev->next = li->next;
	li->next->prev = li->prev;
	free(li->data);
	free(li);
}

void freeLinkedList(LinkedList* l) {
	while (l->current->next != NULL) {
		Link* temp = l->current->next;
		free(l->current->data);
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

void addLinkedList(LinkedList* l, _TYPE* v) {
	Link* newL = (Link*) malloc(sizeof(Link));
	newL->data = v;
	newL->next = l->current->next;
	newL->prev = l->current;
	current->next = newl;
}

void removeLinkedList(LinkedList* l, Link* li) {
	int i = 0;
	while (i < l->size) {
		l->current = l->current->next;
		if (l->current == li) {
			l->current = l->next;
			_freeLink(li);
			break;
		}
		i++;
	}
}
