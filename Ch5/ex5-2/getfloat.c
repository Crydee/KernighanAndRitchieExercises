/* Write getfloat, the floating-point analog of getint.  What type does getfloat retur as its function value? */

#include <ctype.h>
#include <stdio.h>

int getch(void);
float getfloat(float *pf);
int refactored_getint(int *pn);
void ungetch(int);

int main() {
  float i, *pi;

  while ((i = getfloat(pi)))
    printf("Got integer %f\n", *pi);

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

float getfloat(float *pf)
{
  int c, sign;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    int d = c; /* Store off the sign */
    if (!isdigit(c = getch()) && c != '.') { /* Check to see if the next character of input is a digit. */
      if (c != EOF) /* Not a digit, but not EOF, needs to just be pushed back onto the input. */
        ungetch(c);
      ungetch(d);
      return 0; /* Return zero to indicate that the input does not contain an interger value. */
    }
  }
  for (*pf = 0.0; isdigit(c); c = getch())
    *pf = 10 * *pf + (c - '0');
  *pf *= sign;
  if (c == '.') {
    for (int place = 10; isdigit(c = getch()); place *= 10)
      *pf += (float)((c - '0') * sign) / place; /* CRD this is potentially dodgy */
  }
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
