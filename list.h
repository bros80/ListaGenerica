/* Copyrigth (c) 2020 Run 2 Run Software
   Archivo de cabecera "list.h" 

   List representa una estructura de lista
   generica. */

#ifndef __LIST_H__
#define __LIST_H__

typedef struct node {
	void* 		 item;
	struct node* next;
} NodeList;

typedef struct {
	int 		countNodes;
	NodeList* 	root;
} List;

void 		addLast 		(List* , void* , size_t);
List* 		createList 		();
NodeList* 	createNode 		(void* , size_t);
List* 		createQueue 	();
List* 		createStack 	();
void 		deleteList 		(List* );
void 		deleteQueue 	(List* );
void 		deleteStack 	(List* );
void* 		deQueue 		(List* );
void 		enQueue 		(List* , void* , size_t );
NodeList* 	getLastNode 	(List* );
NodeList* 	getPreviousNode (List* );
void 		printList		(List*, void (*fptr) (void* ));
void 		printQueue		(List* , void (*fptr) (void* ));
void 		printStack		(List* , void (*fptr) (void* ));
void* 		pop 			(List* );
void 		push 			(List* , void* , size_t );
void* 		removeFirst 	(List* );
void* 		removeLast 		(List* );

#endif
