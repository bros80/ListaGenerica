/* Copyrigth (c) 2020 Run 2 Run Software
   Programa para testear "list" */

#include <stdio.h>
#include "list.h"
#include "list.c"

void printInt (void* );
void printFloat (void* );

void main () {
	printf ("\n\nPrograma probar la herramienta list");
	printf ("\nPresione una tecla para continuar...");
	getchar ();

	int data[] = {10, 15, 25, 50, 100};
	int i;
	void* value;
	unsigned intSize = sizeof (int);
	List* stack = createStack ();
	for (i = 0; i < 5; i++)
		push (stack, &data[i], intSize);
	printStack (stack, printInt);
	for (i = 0; i < 5; i++) {
		value = pop (stack);
		printStack (stack, printInt);
	}
	deleteStack (stack);

	float data_[] = {10.01, 15.02, 25.03, 50.04, 100.05};
	unsigned floatSize = sizeof (float);
	List* queue = createQueue ();
	for (i = 0; i < 5; i++)
		enQueue (queue, &data_[i], floatSize);
	printQueue (queue, printFloat);
	for (i = 0; i < 5; i++) {
		value = deQueue (queue);
		printStack (queue, printFloat);
	}
	deleteQueue (queue);
	
	printf ("\nEl programa terminó con éxito\n");
}

void printInt (void* value) {
	printf ("\n");
	printf ("%d, ", *(int*) value);
}

void printFloat (void* value) {
	printf ("\n");
	printf ("%f, ", *(float*) value);
}
