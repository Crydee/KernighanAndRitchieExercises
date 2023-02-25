/* Write the function htoi(s), which converts a string of hexa-decimal digits (including an optional 0x or 0X) into its equivalent */
/* integer value.  The allowable digits are 0 through 9, a through f, and A through F. */

#include <stdio.h>

int htoi(char *);
int is_valid_digit(char);
int hex_to_base_10(char); 

int main() {
  char hex_str[] = "0XAbcDeF";

  printf("hex: %s, base 10 val: %d\n", hex_str, htoi(hex_str));

}

int htoi(char s[]) {
  int i, n;
  i = n = 0;

  /* First, check to see if the string starts with '0x' or '0X' and, if so, ignore it. */
  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    i = 2;

  for (i; s[i] != '\0' && is_valid_digit(s[i]); i++) {
    n = 16 * n + (hex_to_base_10(s[i]));
  }

  return n;
}

int is_valid_digit(char c) {

  if (c >= '0' && c <= '9')
    return 1;
  else if (c >= 'a' && c <= 'f')
    return 1;
  else if (c >= 'A' && c <= 'F')
    return 1;
  else
    return 0;
}

int hex_to_base_10(char c) {

  if (c >= '0' && c <= '9')
    return c - '0';
  else if (c >= 'a' && c <= 'f')
    return 10 + c - 'a';
  else if (c >= 'A' && c <= 'F')
    return 10 + c - 'A';
  else
    return -1;
}
