/* As written, getint treats a + or - not followed by a digit as a valid representation of zero.  Fix it to push such
 * a character back on the input.*/

#include <ctype.h>
#include <stdio.h>

int book_getint(int *pn);
int refactored_getint(int *pn);
int getch(void);
void ungetch(int);

int main() {
  int i, *pi;

  while ((i = refactored_getint(pi)))
    printf("Got integer %d\n", *pi);

}
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

int book_getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int refactored_getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    int d = c; /* Store off the sign */
    if (!isdigit(c = getch())) { /* Check to see if the next character of input is a digit. */
      if (c != EOF) /* Not a digit, but not EOF, needs to just be pushed back onto the input. */
        ungetch(c);
      ungetch(d);
      return 0; /* Return zero to indicate that the input does not contain an interger value. */
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
