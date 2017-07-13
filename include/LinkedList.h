#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define _TYPE Vector2
#define _TYPE_SIZE sizeof(_TYPE);

typedef struct Link {
	link* next, prev;
	_TYPE* data;
};

typedef struct LinkedList {
	link* current;
	int size;
};


/*Linked List Functions*/

void initLinkedList(LinkedList*);
LinkedList* newLinkedList();

/* freeLinkedList frees memory associated with each link,
   while deleteLinkedList frees the entire linked list.
   freeLink frees the memory associated with 1 link. */
void _freeLink(Link*);
void freeLinkedList(LinkedList*);
void deleteLinkedList(LinkedList*);

/* Adds the element passed in after the current element. */
void addLinkedList(LinkedList*, _TYPE*);
/* Searches for the element passed as a pointer into the function. */
void removeLinkedList(LinkedList*, Link*);
