/* Copyrigth (c) 2020 Run 2 Run Software
   Archivo de implementación de "list.h" */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void addLast (List* list, void* value, size_t valueSize) {
	if (list->root == NULL) {
		list->root = createNode (value, valueSize);
	}
	else {
		NodeList* ptr = getLastNode (list);
		ptr->next = createNode (value, valueSize);
	}
	list->countNodes++;
}

List* createList () {
	List* list = malloc (sizeof (List));

	list->countNodes = 0;
	list->root = NULL;

	return list;
}

NodeList* createNode (void* value, size_t valueSize) {
	NodeList* ptr = (NodeList*) malloc (sizeof (NodeList));	
	ptr->item = malloc (valueSize);
	ptr->next = NULL;
	// Copia el contenido de value en la nueva memoria alojada.
    // se asume: char toma 1 byte.
    int i;
    for (i = 0; i < valueSize; i++)
    	*(char*)(ptr->item + i) = *(char*)(value + i); 

	return ptr;
}

List* createQueue () {
	return createList ();
}

List* createStack () {
	return createList ();
}

void deleteList (List* list) {
	if (list->countNodes > 0) {
		NodeList* ptr = list->root;
		while (ptr != NULL) {
			NodeList* ptrDel = ptr;
			ptr = ptr->next;
			free (ptrDel);
		}
		free (ptr);
	}

	free (list);
}

void deleteQueue (List* queue) {
	deleteList (queue);
}

void deleteStack (List* stack) {
	deleteList (stack);
}

void* deQueue (List* queue) {
	return removeFirst (queue);
}

void enQueue (List* queue, void* value, size_t valueSize) {
	addLast (queue, value, valueSize);
}

NodeList* getLastNode (List* list) {
	NodeList* ptr = list->root;

	while (ptr-> next != NULL)
		ptr = ptr->next;

	return ptr;
}

NodeList* getPreviousNode (List* list) {
	NodeList* ptr = list->root;
	NodeList* previous = ptr;

	while (ptr->next != NULL) {
		previous = ptr;
		ptr = ptr->next;
	}

	return previous;
}

void printList (List* list, void (*fptr) (void* )) {
	NodeList* ptr = list->root;

	while (ptr != NULL) {
		(*fptr) (ptr->item);
		ptr = ptr->next;
	}
}

void printQueue (List* queue, void (*fptr) (void* )) {
	printList (queue, (*fptr));
}

void printStack (List* stack, void (*fptr) (void* )) {
	printList (stack, (*fptr));
}

void* pop (List* stack) {
	return removeLast (stack);
}

void push (List* stack, void* value, size_t valueSize) {
	addLast (stack, value, valueSize);
}

void* removeFirst (List* list) {
	void* value = NULL;

	if (list->root != NULL) {
		NodeList* ptr = list->root;
		list->root = ptr->next;
		--list->countNodes;
		value = ptr->item;
	}

	return value;
}

void* removeLast (List* list) {
	NodeList* ptr = getPreviousNode (list);
	void* value;

	if (list->countNodes == 1)
		value = ptr->item;
	else {
		NodeList* last = ptr->next;
		value = last->item;
	}

	ptr->next = NULL;
	--list->countNodes;
	if (list->countNodes == 0)
		list->root = NULL;
	
	return value;	
}
