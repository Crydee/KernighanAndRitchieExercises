/* rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing.  Good possibilities
 * include getline, atoi, itoa, and their variants, reverse, and strindex and getop. */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int ptr_atoi(char *s);
int ptr_getline(char *s, int lim);
void ptr_itoa(int n, char *s);
void rec_ptr_itoa(int n, char *s);
void reverse(char *s);
int ptr_strindex(char *s, char *t);

int main() {
  char input[100], atoi_in[] = "12345";
  int n = -12345;
  printf("The char with value 97 is: %c\n", 97);
  printf("Test our pointer version of getline by providing some input:\n");
  ptr_getline(input, 100);
  printf("Input was %s", input);

  printf("Test our pointer version of atoi by providing a string of digits (optionally preceeded by a '+' or '-':\n");
  ptr_getline(input, 100);
  int result = ptr_atoi(input);
  printf("Calling pointer atoi on %s gave: %d\n", input, result);

  printf("Testing our pointer version of itoa by mapping the resulting int back to a string.\n");
  ptr_itoa(result, input);
  printf("calling itoa on %d gives %s\n", result, input);

  char needle[] = "fox", heystack[] = "The quick brown fox jumps over the lazy dog.";
  printf("Testing our pointer version of strindex by searching for the string %s in %s\n", needle, heystack);
  int loc = ptr_strindex(heystack, needle);
  printf("calling ptr_strindex searching for the string %s in %s gives: %d\n", needle, heystack, loc);
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
  int n = 0, sign;
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

/* reverse: reverse the string s. */
void reverse(char *s) {
  char *j;
  int c;
  for (j = s + (strlen(s) - 1); s < j; s++, j--) {
    c = *s;
    *s = *j;
    *j = c;
  }
}

/* ptr_itoa: convert n to characters in s. */
void ptr_itoa(int n, char *s) {
  int positive = 0;
  char *start = s;

  if (n > 0) {
    n *= -1;
    positive = 1;
  }

  do {
    *s++ = '0' - n % 10;
  } while (n /= 10);

  if (!positive)
    *s++ = '-';
  *s = '\0';
  reverse(start);
}

/* rec_ptr_itoa: recursively convert n to characters in s. */
void rec_ptr_itoa(int n, char *s) {
  static int position;
  if (n/10) {
    ptr_itoa(n/10, s);
  }
  else {
   position = 0;
   if (n < 0)
     *(s + position++) = '-';
  }
  if (n > 0)
    n = -n;
  *(s + position++) = '0' - n%10;
  *(s + position) = '\0';
}

/* ptr_strindex: return index of t in s, -1 if none. */
int ptr_strindex(char *s, char *t) {
  char *i, *j, *start = s;

  for (; *s != '\0'; s++) {
    for (i = s, j = t; (*j != '\0') && (*j == *i); i++, j++)
      ;
    if (j > t && *j == '\0') /* Check to see if we have a match. */
      return s- start;
  }
  return -1;
}
