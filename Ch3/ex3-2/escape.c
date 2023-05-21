/* Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch.  Write a function for the other direction as well, converting escape sequences into the real characters. */

#include <stdio.h>

int escape(char s[], char t[]);
int unescape(char s[], char t[]);

#define S_LENGTH 10000
int main() {
  char s[S_LENGTH], t[] = "There's \vsome odd\t stuff \ in ' this \" ar\fray?";

  printf("The unescaped test arr is:%s\n", t);
  escape(s, t);
  printf("The escaped output arr is:%s\n", s);
}

/*We will assume that there's room for the converted string in s*/
int escape(char s[], char t[]) {
  int i, j, c, count;
  
  for (i = j = 0; (c = t[i]) != '\0'; i++) {
    switch (c) {
      case '\t': 
        s[j++] = '\\';
        s[j++] = 't';
        count++;
        break;
      case '\n': 
        s[j++] = '\\';
        s[j++] = 'n';
        count++;
       break;
      case '\f': 
        s[j++] = '\\';
        s[j++] = 'f';
        count++;
        break;
      case '\v': 
        s[j++] = '\\';
        s[j++] = 'v';
        count++;
        break;
      case '\\': 
        s[j++] = '\\';
        s[j++] = '\\';
        count++;
        break;
      case '\'': 
        s[j++] = '\\';
        s[j++] = '\'';
        count++;
        break;
      case '\"': 
        s[j++] = '\\';
        s[j++] = '\"';
        count++;
        break;
      case '\?': 
        s[j++] = '\\';
        s[j++] = '\?';
        count++;
        break;
      default:
        s[j++] = c;
        break;
   }
  } 
  s[j] = '\0';
  return count;
}
