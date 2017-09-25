#include <stdio.h>

int main() {

  /*
   * Declare an integer variable and a pointer to an integer.  Initialize
   * the pointer to point to the memory location occupied by the original
   * integer.
   */

  int i = 20;
  int* i_ptr = &i;

  /*
   * Print the value of our integer, the value of our pointer, and the
   * memory address of the integer, the latter two of which will be the same.
   */
  printf("i: %d\n", i);
  printf("i_ptr: %p\n", i_ptr);
  printf("&i: %p\n", &i);
}
