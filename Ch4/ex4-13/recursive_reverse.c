/* Write a recursive  ersion of teh function reverse(s), which reerrses the string s in place. */

#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void rec_reverse(char *, int i, int j);

int main(int argc, char *argv[])
{
  printf("The un-reversed string is %s ", argv[1]);
  reverse(argv[1]);
  printf("The reversed string is: %s\n", argv[1]);
}


void rec_reverse(char *s, int i, int j)
{
  char temp;

  if (i >= j)
    return;

  temp = s[j];
  s[j] = s[i];
  s[i] = temp;
  rec_reverse(s, ++i, --j);
}

void reverse(char s[])
{
  int i = 0, j = strlen(s);
  rec_reverse(s, i, --j);
}
