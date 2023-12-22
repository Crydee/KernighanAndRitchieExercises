/* rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing.  Good possibilities
 * include getline, atoi, itoa, and their variants, reverse, and strindex and getop. */

#include <stdio.h>

int ptr_getline(char *s, int lim);

int main() {
  char input[100];

  ptr_getline(input, 10);
  printf("Input was %s", input);

}

/* ptr_getline: get line into s, return length. */
int ptr_getline(char *s, int lim) {
  int c;
  char * start = s;

  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    *s++ = c; /* Make sure this correctly increments s and doesn't increment the character that s points to. */
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s - start;
}
