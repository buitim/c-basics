#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main()
{
    /*
   * Note that when initializing a string with a constant (i.e. with a string
   * "inside double quotes"), that string points to a location in read-only
   * memory and can't be modified.  The string should thus be declared as
   * const.  By doing this, trying to modify it, as in the commented-out line
   * below, becomes a compile-time error instead of a runtime error.
   */
    const char *name = "Prancess Leia";
    // name[2] = 'i';

    /*
   * To create strings we can manipulate, we need to allocate memory for them
   * on the heap.  Note that strings in C are just arrays of characters.
   *
   * Below, we use the functions strlen() and strcpy() from the C string.h
   * library to make a mutable copy of the constant string above, so we can
   * fix the spelling error it contains.  Specifically, we do the following:
   *
   *   - Use strlen() to determine the number of characters in name.
   *   - Use that number of characters to allocate space for a new string into
   *     which we can copy name.  Note that C uses an extra character at the
   *     end of strings to indicate where the string ends (the character used
   *     is the null character, '\0'), so when allocating space for a string,
   *     we need to make sure there is space for an extra character to store
   *     this terminating null character.  This is why we add 1 to the length
   *     of name when allocating our new string below.
   *   - Use strcpy() to copy the contents of name into the new memory we
   *     just allocated.
   *   - Correct the spelling mistake in the copied string.
   */
    int len = strlen(name);
    char *copy = malloc((len + 1) * sizeof(char));
    strcpy(copy, name);
    copy[2] = 'i';
    printf("copy: %s\n", copy);
}
