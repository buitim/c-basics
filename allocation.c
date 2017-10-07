#include <stdio.h>
#include <stdlib.h> /* You need to include stdlib.h to use malloc() */

/* A struct to hold data associated with a single student. */
struct student
{
    char *name;
    int standing;
    double gpa;
};

int main()
{

    /*
   * Use malloc() to allocate space for a single integer on the heap.  We use
   * sizeof() to tell us how many bytes an element of a particular data type
   * needs.
   */
    int *i = malloc(sizeof(int));
    printf("sizeof(int): %lu\n", sizeof(int));

    /*
   * Update the value stored at the memory address pointed to by i by
   * dereferencing i.
   */
    *i = 16;
    printf("*i: %d\n", *i);
    printf("&i: %p\n", &i);
    printf("i: %p\n", i);

    /*
   * We can also use malloc() to allocate memory on the heap for an array.
   * Here, we dynamically allocate an array of 256 integers and initialize
   * the values of the elements of the array.
   */
    int j, n = 256;
    int *array = malloc(n * sizeof(int));
    for (j = 0; j < n; j++)
    {
        array[j] = j;
    }

    /*
   * Here, we're printing different values associated with our array.  Note
   * that both array and &array[0] are the same address.  Specifically, they
   * both point to the beginning of the chunk of memory we allocated above.
   * In particular, note that we can dereference array itself to modify the
   * value of array[0].
   */
    printf("\n\n");
    printf("array: %p\n", array);
    printf("&array[0]: %p\n", &array[0]);
    printf("array[0]: %d\n", array[0]);
    printf("array[10]: %d\n", array[10]);
    *array = 100;
    printf("array[0]: %d\n", array[0]);

    /*
   * We can also use malloc() to dynamically allocate memory for a struct.
   * Note that to access the fields of a struct when we have a pointer to
   * that struct, we need to dereference the pointer.  The arrow operator
   * (i.e. ->) both dereferences a struct pointer and accesses one of its
   * fields.
   */
    struct student *s = malloc(sizeof(struct student));
    printf("sizeof(struct student): %lu\n", sizeof(struct student));
    s->name = "Luke Skywalker";
    printf("s->name: %s\n", s->name);

    /*
   * We allocate an array of structs the same way as we allocate an array
   * of ints, multiplying the size of the struct by the number we want to
   * allocate, and passing the resulting number of bytes to malloc.
   *
   * We can access the fields of the elements of an array of structs using the
   * dot operator, as below.
   */
    int m = 64;
    struct student *students = malloc(m * sizeof(struct student));
    for (j = 0; j < m; j++)
    {
        students[j].name = "Luke Skywalker";
        students[j].standing = 1;
        students[j].gpa = 4.0;
    }
    printf("\n\n");
    printf("students[4].name: %s\n", students[4].name);

    /*
   * A 2D array is actually represented as a 1D array of 1D arrays, i.e. a
   * pointer to an array of pointers, each of which points to a 1D array of
   * elements.  To allocate a 2D array, we need to allocate memory for the
   * outer 1D array of pointers, and then allocate a 1D array for each of
   * those pointers to point to.
   *
   * Here's how it would look to allocate an m x n array of ints.
   */
    int **matrix = malloc(m * sizeof(int *));
    for (j = 0; j < m; j++)
    {
        matrix[j] = malloc(n * sizeof(int));
    }

    /*
   * It's very important to free all of the memory you allocate so your
   * program doesn't leak memory.  Let's use the free() function to free all
   * of the memory we allocated above.
   */
    free(i);
    free(array);
    free(s);
    free(students);

    /*
   * In order to free the memory allocated to our 2D array, we need to reverse
   * what we did to allocate it.  Specifically, we need to free each of the
   * inner 1D arrays of ints before we free the outer 1D array of pointers.
   */
    for (j = 0; j < m; j++)
    {
        free(matrix[j]);
    }
    free(matrix);
}
