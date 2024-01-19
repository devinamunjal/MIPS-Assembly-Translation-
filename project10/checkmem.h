/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
 * not to provide it to anyone else. */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
   SERVER */

/* enables heap consistency and correctness checking */
void setup_memory_checking(void);
/* returns the amount of allocated memory currently in the heap */
int get_memory_in_use(void);
/* performs consistency and correctness checking for the entire heap */
void check_heap(void);
