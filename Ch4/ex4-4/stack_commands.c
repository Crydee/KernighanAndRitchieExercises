/* this program forms the basis on which exercises 4-3 through 4-10 build */
/* Given the basic framework, it's straightforward to extend the calculator.  Add the modulus (%) operator and
 * provisions for negative numbers. */
/* To Do: currenly whenever a user hits enter after any input the top of the stack is popped.  We don't want this when we're using the stack commands
 * that we've just added. */
#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void show_top(void);
void clear_stack();

/* reverse Polish calculator */

int main(void)
{
  int type;
  double op2;
  double top_elt;
  char s[MAXOP];

  while((type = getop(s)) != EOF)
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
      case '%':
        op2 = pop();
        if(op2 != 0.0)
          push(fmod(pop(), op2));
        else
          printf("error: zero divisor\n");
        break;
      case 'p':
        show_top();
        break;
      case 'd':
        top_elt = pop();
        push(top_elt);
        push(top_elt);
        break;
      case 's':
        top_elt = pop();
        op2 = pop();
        push(top_elt);
        push(op2);
        break;
      case 'z':
        clear_stack();
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

/* show_top: print the top element of the stack without popping it */
void show_top(void) {
  if(sp > 0)
    printf("Top element of stack: %f\n", val[sp - 1]);
  else
    printf("Cannot print top element, stack is empty\n");
}

/* clear_stack: clear the stack. */
void clear_stack(void) {
  printf("Clearing stack, %d elements cleared.\n", sp);
  sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  if(!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */

  i = 0;
  /* Check if we have a - character, as that could be either the start of a negative number, or the minus operator.
   * We get the next character and if it is a digit or '.' then we have a negative number so we go on as if we had a '.' or
   * a digit, otherwise we assume we have the minus operator.*/
  if(c == '-') {
    c = getch();

    if(!isdigit(c) && c != '.') {
    /* In this case we have a '-' followed by something other than a digit or '.', so we treat the - as the minus
     * operator. */
        ungetch(c);
        return '-';
    }
    /* Since we've not returned, c must be either a digit or '.', so continue on. */
    s[++i] = c;
  }
  if(isdigit(c)) /* collect integer part */
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
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
