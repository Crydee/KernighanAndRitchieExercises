/* Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch.  Write a function for the other direction as well, converting escape sequences into the real characters. */

#include <stdio.h>

int escape(char s[], char t[]);
int unescape(char s[], char t[]);

#define S_LENGTH 10000
int main() {
  char s[S_LENGTH], t[] = "There's \nsome odd\n stuff \ in ' this \n ar\nray?", w[S_LENGTH];

  printf("The unescaped test arr is:%s\n", t);
  escape(s, t);
  printf("The escaped output arr is:%s\n", s);
  unescape(w, s);
  printf("Calling unescape of the output gives:%s\n", t);
}

/*We will assume that there's room for the converted string in s*/
int escape(char s[], char t[]) {
  int i, j, count = 0;
  
  for (i = j = 0; t[i] != '\0'; i++) {
    switch (t[i]) {
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
        s[j++] = t[i];
        break;
   }
  } 
  s[j] = '\0';
  return count;
}
/* This is easier to write succinctly, as we just need to look out for un-escaped backslashes and print '/<the next char>*/
int unescape(char s[], char t[]) {

  int i, j, count = 0 ;

  for(i = j = 0;  t[i] != '\0'; i++, j++, count++) {

    switch (t[i]){

      case '\\':
        switch (t[++i]) {
          case 'n':
            s[j] = '\n';
            count++;
            break;
          case 't':
            s[j] = '\t';
            count++;
            break;
          case 'f':
            s[j] = '\f';
            count++;
            break;
          case 'v':
            s[j] = '\v';
            count++;
            break;
          case '\\':
            s[j] = '\\';
            count++;
            break;
          default:
            s[j] = '\\';
            s[++j] = t[i];
            break;
        }
        break;

      default:
        s[j] = t[i];
        break;
    }
  }
  s[j] = t[i]; /*Null terminate the array*/
  return count;
}

