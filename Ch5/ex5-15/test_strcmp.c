#include <ctype.h>
#include <stdio.h>
#include <string.h>

int mod_strcmp(char *str_one, char *str_two, int case_insensitive) {
  if (!case_insensitive)
    return strcmp(str_one, str_two);

  else {
    for (; tolower(*str_one) == tolower(*str_two); str_one++, str_two++)
      if (*str_one == '\0')
        return 0;
    return *str_one - *str_two;
  }
}

int main(int argc, char *argv[])
{
  char *str_one = "I WAS THE SHADOW OF THE WAXWING.\n";
  char *str_two = "i was the shadow of the waxwing.\n";

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
