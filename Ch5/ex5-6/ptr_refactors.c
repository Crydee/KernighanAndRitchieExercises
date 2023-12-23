/* rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing.  Good possibilities
 * include getline, atoi, itoa, and their variants, reverse, and strindex and getop. */

#include <ctype.h>
#include <stdio.h>

int ptr_atoi(char *s);
int ptr_getline(char *s, int lim);

int main() {
  char input[100], atoi_in[] = "12345";

  ptr_getline(input, 10);
  printf("Input was %s", input);
  printf("Calling pointer atoi on %s gave: %d\n", input, ptr_atoi(input));

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

/* ptr_atoi: convert s to integer; ptr version, based on version on P61. */
int ptr_atoi(char *s) {
  int n, sign;
  /* Skip whitespace */
  while (isspace(*s))
    s++;
  sign = (*s == '-') ? -1 : 1;
  if (*s == '-' || *s == '+') /* Skip sign. */
    s++;
  while (isdigit(*s))
    n = 10 * n + (*s++ - '0');
  return sign * n;
}
