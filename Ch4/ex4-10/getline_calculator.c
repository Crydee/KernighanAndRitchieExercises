/* this program forms the basis on which exercises 4-3 through 4-10 build */

#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char input_line[], char output_line[]);
void push(double);
double pop(void);
int get_line(char line[], int lim);

/* reverse Polish calculator */

int main(void)
{
  int type;
  double op2;
  char s[MAXOP], input_line[1000];

  get_line(input_line, 1000);
  printf("input line is: %s\n", input_line);
  while((type = getop(input_line, s)) > 0)
  {
    switch(type)
    {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }

  return 0;
}

#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int ndex = 0;
/* getop: get next operator or numeric operand */
int getop(char input_line[], char s[])
{
  int i, c;

  while((s[0] = c = input_line[ndex++]) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;
  if(isdigit(c)) /* collect integer part */
    while(isdigit(s[++i] = c = input_line[ndex++]))
      ;
  if(c == '.')
    while(isdigit(s[++i] = c = input_line[ndex++]))
      ;
  s[i] = '\0';
  if(c != EOF)
    ndex--;
  return NUMBER;
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

int get_line(char line[], int lim) {
  int c, ii;

  for (ii = 0; (ii < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ii++)
  {
    line[ii] = c;
  }
  if (c == '\n')
  {
    line[ii] = c;
    ii++;
  }
  line[ii] = '\0';
  return ii;
}
