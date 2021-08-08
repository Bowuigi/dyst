/*
 Single header, portable POSIX C99 dynamic stack library
 Is able to push, pop and read from any index of the stack
 By Bowuigi

 -- License (zlib) --
 Copyright (C) 2021 Bowuigi

 This software is provided 'as-is', without any express or implied
 warranty.  In no event will the authors be held liable for any damages
 arising from the use of this software.

 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it
 freely, subject to the following restrictions:

 1. The origin of this software must not be misrepresented; you must not
 claim that you wrote the original software. If you use this software
 in a product, an acknowledgment in the product documentation would be
 appreciated but is not required.

 2. Altered source versions must be plainly marked as such, and must not be
 misrepresented as being the original software.

 3. This notice may not be removed or altered from any source distribution.

 -- Functions --

 +----------+--------------+------------------------------------------------------+
 |  return  |  name        |  arguments                                           |
 |----------|--------------|------------------------------------------------------|
 |  dyst    |  dyst_new    |  (size_t length, size_t type_size);                  |
 |  void    |  dyst_delete |  (dyst *stack);                                      |
 |  int     |  dyst_resize |  (dyst *stack, size_t new_length);                   |
 |  int     |  dyst_push   |  (dyst *stack, void *element, size_t element_size);  |
 |  void*   |  dyst_pop    |  (dyst *stack);                                      |
 +----------+--------------+------------------------------------------------------+

 -- Limitations --
 Like in most dynamic array implementations, a cast to (void*) is required to add data to the stack, another cast to use the data stored in the stack is also needed.
 An example can be found on the test.c file
*/

#ifndef DYST_H
#define DYST_H

//#include <sys/types.h>
#include <stdlib.h>

// The dynamic stack structure
typedef struct dyst {
	size_t length;
	size_t used;
	void **stack;
} dyst;

// Create a new dynamic stack with an allocated size equivalent to 'size'*'type_size', you must call 'dyst_free' after you finish using the stack
dyst dyst_new(size_t length, size_t type_size) {
	static dyst tmp;
	tmp.stack=calloc(length,sizeof(void*));
	tmp.length=length;
	tmp.used=0;
	return tmp;
}

// Deletes a dynamic stack, preventing a memory leak
void dyst_delete(dyst *stack) {
	free(stack->stack);
}

// Resize a dynamic stack to fit in 'new_length'*'stack.type_size'
int dyst_resize(dyst *stack, size_t new_length) {

	// Return if trying to reduce enough to lose data
	if (new_length<stack->used)
		return 1;

	void *tmp=realloc(stack->stack, new_length * sizeof(void*));

	// Return if allocation fails
	if (tmp==NULL)
		return 1;

	// Setting the required values
	stack->stack=tmp;
	stack->length=new_length;
	return 0;
}

// Add an element at the end of the dynamic stack
int dyst_push(dyst *stack, void *element, size_t element_size) {
	if (stack->used+1 > stack->length) {
		stack->length *= 2;
		int r = dyst_resize(stack,stack->length);
		if (r==1)
			return 1;
	}
	stack->stack[stack->used++] = element;
	return 0;
}

void *dyst_pop(dyst *stack) {
	stack->used--;
	void *i=stack->stack[stack->used];
	stack->stack[stack->used]=NULL;
	return i;
}

#endif
