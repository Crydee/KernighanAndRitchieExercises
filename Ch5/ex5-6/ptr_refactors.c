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

int main() {
  char input[100], atoi_in[] = "12345";
  int n = -12345;
//  ptr_getline(input, 10);
//  printf("Input was %s", input);
//  printf("Calling pointer atoi on %s gave: %d\n", input, ptr_atoi(input));
//  for (int i = 0; i < 100; i++)
//    input[i] = 'a';
  printf("the contents of input is: %s\n", input);
  ptr_itoa(n, input);
  printf("calling itoa on %d gives %s\n", n, input);
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

/* reverse: reverse the string s. */
void reverse(char *s) {
  int c, i, j, len = strlen(s);
  for (i = 0, j = --len; i < j; i++, j--) {
    c = *(s + i);
    *(s + i) = *(s + j);
    *(s + j) = c;
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
