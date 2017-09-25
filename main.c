#include <stdio.h>

/* A struct to hold data associated with a single student. */
struct student {
  char* name;
  int standing;
  double gpa;
};

/* A function prototype. */
void foo(int x);

int main(int argc, char** argv) {

  int i;
  double pi = 3.1415;
  char a = 'a';

  /*
   * Printing a floating point number with printf() using the %f placeholder.
   * The printed number will have 16 total characters, with 4 characters after
   * the decimal point, and it'll be zero-padded at the front.
   */
  printf("pi is: %016.4f\n", pi);

  /* Printing a single character with printf() with the %c placeholder. */
  printf("a is: %c\n", a);

  /*
   * Printing the command line arguments with printf().  The index of the
   * command line argument being printed is an integer, so we use %d as its
   * placeholder.  Each index will be allocated 8 characters in the printed
   * string.  The command line argument itself is a string (i.e. a char*),
   * so we use %s as its placeholder.
   */
  for (i = 0; i < argc; i++) {
    printf("argv[%8d]: %s\n", i, argv[i]);
  }

  /* Calling the function foo(). */
  foo(2);
  foo(16);

  /*
   * Instantiating a student struct and initializing it using a designated
   * initializer.
   */
  struct student s = {
    .name = "Luke Skywalker",
    .gpa = 4.0
  };

  /* We could also set the values of our struct like this. */
  // s.name = "Luke Skywalker";
  s.standing = 2;
  // s.gpa = 4.0;

  printf("%s\t%d\t%f\n", s.name, s.standing, s.gpa);

  return 0;
}

/* Our definition for the function foo(). */
void foo(int x) {
  printf("in foo(), we got %d.\n", x);
}
