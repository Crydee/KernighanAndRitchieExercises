/* Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else. */
#include <stdio.h>

int lower(int c);

main() {
  int ii = 0;
  char test_str[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.12345";

  printf("The test string is: %s\n", test_str);

  printf("The result of calling lower() on each character in the string is : ");
  while (test_str[ii] != '\0')
    printf("%c", lower(test_str[ii++]));

  printf("\n");
}

int lower(int c) {
  return ('A' <= c && c <= 'Z') ? c + 'a' - 'A' : c;
}
