/* Wtiet the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise. */
#include <stdio.h>

int strend(char *s, char *t);

int main() {
  char s[100] = "abcdef01234", t[100] = "01234";

  printf("s is: %s\n", s);
  printf("t is: %s\n", t);

  if (strend(s,t))
    printf("t occurs at the end of s\n");
  else
   printf("t does not occur at the end of s\n");

}

/* strend: return 1 if the string t occurs at the end of the string s, and zero otherwise. */
int strend(char *s, char *t) {

  /* Save off the beginning of the strings. */
  char *pbs = s, *pbt = t;

  /* Find the end of the strings. */
  while(*s)
    s++;
  while(*t)
    t++;
  /* Walk back through the strings and see if they match. */
  for(; (*s == *t) && (t != pbt); s--, t--)
    ;
  /* We have a match if we have marched all the way to the beginning of t and the characters still match. */
  if ((*s == *t) && (t == pbt))
    return 1;
  else
   return 0;
}
