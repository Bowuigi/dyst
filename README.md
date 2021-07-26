# dyst

A simple and portable dynamic stack implementation in POSIX C99

Adding it into a project
---

- Copy the dyst.h file to the project
- Include it:
	- On C
	```c
	#include "dyst.h"
	```

	- On C++

	```cpp
	extern C {
		#include "dyst.h"
	}
	```

	- Done!

Functions
---

The functions are pretty self explanatory

`dyst` is the dynamic stack data structure

+----------+--------------+------------------------------------------------------+
|  return  |  name        |  arguments                                           |
|----------|--------------|------------------------------------------------------|
|  dyst    |  dyst_new    |  (size_t length, size_t type_size);                  |
|  void    |  dyst_delete |  (dyst *stack);                                      |
|  int     |  dyst_resize |  (dyst *stack, size_t new_length);                   |
|  int     |  dyst_push   |  (dyst *stack, void *element, size_t element_size);  |
|  void*   |  dyst_pop    |  (dyst *stack);                                      |
+----------+--------------+------------------------------------------------------+

Help
---

An example can be found in the test.c file

For more information see the dyst.h file
