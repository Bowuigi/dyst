#include "dyst.h"
#include <stdio.h>
#include <stdint.h>

int main() {
	printf("Creating a dynamic stack...\n");
	// Create a dynamic stack of type int and initial size of 5
	dyst d = dyst_new(5,sizeof(int));
	printf("\n");

	// Add 6 values to the stack (1,2,3,4,5,6) and display information
	for (uintptr_t i=1;i<=6;i++) {
		// Pushing requires the stack adress, the element to add (casted to void*) and its size
		printf("Adding %lu to the dynamic stack... [%i]\n",i,dyst_push(&d , (void*)i, sizeof(i)));
		printf("\n");

		printf("Displaying the value\n");
		// Displaying requires the value to be casted to its original datatype
		printf("%lu\n",(uintptr_t)d.stack[d.used-1]);
		printf("\n");

		printf("Displaying info\nUsed: %zu Length: %zu\n",d.used,d.length);
	}

	printf("Removing a value from the dynamic stack\n");
	void *v=dyst_pop(&d);
	printf("\n");

	printf("Displaying the value\n");
	printf("%lu -> %lu\n",(uintptr_t)v,(uintptr_t)d.stack[d.used]);
	printf("\n");

	printf("Displaying info\nUsed: %zu Length: %zu\n",d.used,d.length);

	printf("Deleting the dynamic stack...\n");
	dyst_delete(&d);
	printf("Finished test\n");
}
