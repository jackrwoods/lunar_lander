
/* Doubly-Linked List Implementation by Jack Woods */

#include "../include/LinkedList.hpp"


void initLinkedList(LinkedList* l) {
	l->current = new Link;
	if (l->current != NULL) {
		l->size++;
		/* The sentinel, which denotes the beginning of the LL,
		   has its data initialized to NULL */
		l->current->next = l->current;
		l->current->prev = l->current;
		l->current->data = NULL;
	}
}

LinkedList* newLinkedList() {
	LinkedList* l = new LinkedList;
	if (l != NULL){
		initLinkedList(l);
		return l;
	}
	return NULL;
}

void _freeLink(Link* li) {
	if (li != NULL) {
		Link* temp = li;
		li->prev->next = li->next;
		li->next->prev = li->prev;
		delete(li->data);
		delete(li);
	}
}

void freeLinkedList(LinkedList* l) {
	while (l->current->next != NULL) {
		Link* temp = l->current->next;
		delete(l->current->data);
		delete(l->current);
		l->current = temp;
	}
	delete(l->current);
	l->current = NULL;
}

void deleteLinkedList(LinkedList* l) {
	freeLinkedList(l);
	delete(l);
}

void addLinkedList(LinkedList* l, _TYPE* v) {
	Link* newL = new Link();
	newL->data = v;
	newL->next = l->current->next;
	newL->prev = l->current;
	l->current->next = newL;
}

void removeLinkedList(LinkedList* l, Link* li) {
	int i = 0;
	while (i < l->size) {
		l->current = l->current->next;
		if (l->current == li) {
			l->current = l->current->next;
			_freeLink(li);
			break;
		}
		i++;
	}
}

void getLinkedList(LinkedList* l, int val) {
	while (val > current->data && current->data < current->next->data) {
		current = current->next;
	}
}
