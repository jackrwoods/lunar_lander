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

void freeLinkedList(LinkedList*);
void deleteLinkedList(LinkedList*);

void addLinkedList(LinkedList*, Vector2*);
void removeLinkedList(LinkedList*, Link*);
