#include "dyst.h"
#include <stdio.h>

int main() {
	printf("Creating a dynamic stack...\n");
	// Create a dynamic stack of type int and initial size of 5
	dyst d = dyst_new(5,sizeof(int));
	printf("\n");

	// Add 6 values to the stack (1,2,3,4,5,6) and display information
	for (int i=1;i<=6;i++) {
		// Pushing requires the stack adress, the element to add (casted to void*) and its size
		printf("Adding %i to the dynamic stack... [%i]\n",i,dyst_push(&d , (void*)i, sizeof(i)));
		printf("\n");

		printf("Displaying the value\n");
		// Displaying requires the value to be casted to its original datatype
		printf("%i\n",(int)d.stack[d.used-1]);
		printf("\n");

		printf("Displaying info\nUsed: %zu Length: %zu Type size: %zu\n",d.used,d.length,d.type_size);
	}

	printf("Removing a value from the dynamic stack\n");
	void *v=dyst_pop(&d);
	printf("\n");

	printf("Displaying the value\n");
	printf("%i -> %i\n",(int)v,(int)d.stack[d.used]);
	printf("\n");

	printf("Displaying info\nUsed: %zu Length: %zu Type size: %zu\n",d.used,d.length,d.type_size);

	printf("Deleting the dynamic stack...\n");
	dyst_delete(&d);
	printf("Finished test\n");
}
