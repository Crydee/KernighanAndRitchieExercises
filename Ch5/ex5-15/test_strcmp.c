#include <stdio.h>
#include <string.h>

int mod_strcmp(char *str_one, char *str_two, int case_insensitive) {
  if (!case_insensitive)
    return strcmp(str_one, str_two);

  else {
    /* Go through the strings till we find characters that don't evaluate to equal, or we reach the end of a string. */
    while (*str_one) {
      if (*str_one == *str_two)
        str_one++, str_two++;
      else if ((*str_one == (*str_two + 'A' - 'a')) || (*str_two == (*str_one + 'A' - 'a')))
          str_one++, str_two++;
      else
       break;
    } 
    return *str_one - *str_two;
  }
}

int main(int argc, char *argv[])
{
  char *str_one = "I was the shadow of the waxwing.\n";
  char *str_two = "I WAS THE SHADOW OF THE WAXWING.\n";
  
  printf("The test strings are:\n\t%s\t%s", str_one, str_two);

  int result = mod_strcmp(str_one, str_two, 0);
  if (result > 0)
    printf("The first string is greater than the second.\n");
  else if (result < 0)
    printf("The second string is greater than the first.\n");
  else
    printf("The two strings are equal!\n");

  int case_ins_result = mod_strcmp(str_one, str_two, 1);
  printf("Case insensitive comparison ==========\n");
  if (case_ins_result > 0)
    printf("The first string is greater than the second.\n");
  else if (case_ins_result < 0)
    printf("The second string is greater than the first.\n");
  else
    printf("The two strings are equal!\n");
}
