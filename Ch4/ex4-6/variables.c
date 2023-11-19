/* this program forms the basis on which exercises 4-3 through 4-10 build */
/*Add access to library functions like sin, exp, and pow. */

#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define STRING -10 /* signal that a string was found */

int getop(char []);
int handle_cmd(int);
int handle_string(char *);
double pop(void);
void push(double);
void show_top(void);
void clear_stack();

/* reverse Polish calculator */

int main(void)
{
  int type, no_pop = 0;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF)
  {
    switch(type)
    {
      case '#': case '?': case '@': case '!':
        no_pop = handle_cmd(type);
        break;
      case NUMBER:
        push(atof(s));
        break;
      case STRING:
        no_pop = handle_string(s);
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
      case '\n':
        /* We don't want to pop the top of the stack when we just want to display the output of a command. */
        if(!no_pop)
          printf("\t%.8g\n", pop());
        else
          no_pop = 0;
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

/* str_equal: Check if two strings are identical. */
int str_equal(char* s, char* c) {
  int i;
  i = 0;
  while((s[i] == c[i]) && (s[i] != '\0') && (c[i] != '\0'))
    i++;

  if((s[i] == c[i]) && s[i] == '\0') /* The strings match from beginning to end.*/
    return 1;
  return 0;
}

/* handle_string: handle strings returned by getop.*/
int handle_string(char * stack) {
  if (strcmp(stack, "sin") == 0) {
    if (sp) {
      push(sin(pop()));
    }
    else
      printf("We need at least one value on the stack to call sin\n");
  }
  else if (strcmp(stack, "pow") == 0) {
    if (sp >= 2) {
    /* We need at least two values on the stack for us to call pow, since we need a base and an exponent.*/
    double exponent = pop();
    push(pow(pop(), exponent));
    }
    else
      printf("We need at least two values on the stack to call pow\n");
    }
  else if (strcmp(stack , "exp") == 0) {
    if (sp) {
      push(exp(pop()));
    }
    else
      printf("We need at least one value on the stack to call exp\n");
  }
  else
    printf("The string provided, %s, didn't match any supported function\n", stack);
  return 0;
}

/* handle_cmd: Handle commands that manipulate or display the stack. */
int handle_cmd(int op) {
  int no_pop = 0; /* Whether or not to pop the top value of the stack on the next press of the enter key.*/
  double top_elt, second_elt;
  switch (op) {
    case '#':
      /* Duplicate the top element of the stack.*/
      no_pop = 1;
      push(top_elt = pop());
      push(top_elt);
      break;
    case '?':
      /* Display the top element of the stack, without popping it.*/
      no_pop = 1;
      show_top();
      break;
    case '@':
      /* Swap the top two elements of the stack, without popping them. */
      no_pop = 1;
      top_elt = pop();
      second_elt = pop();
      push(top_elt);
      push(second_elt);
      break;
    case '!':
      /* Clear the stack */
      clear_stack();
      break;
    default:
      /* We should only end up here if we read a character we don't understand.*/
      no_pop = 1;
      printf("%c is not a valid command", op);
   }
  return no_pop;
}
/* show_top: print the top element of the stack without popping it */
void show_top(void) {
  if(sp)
    for(int i = sp - 1; i >= 0; i--)
      printf("%f\n", val[i]);
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

  /* Skip whitespace.*/
  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  i = 0;
  if(isalpha(c)) { /* If we get an alphabetic character then keep getting more until we get something else.*/
    while(isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if(c != EOF)
      ungetch(c);
    return STRING;
  }
  if(!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */

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
