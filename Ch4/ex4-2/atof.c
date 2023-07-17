/* Extend atof to handle scientific notation of the form 123.45e-6 where a floating point number may be followed by e or E and an optionally
 * signed exponent */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);
double extended_atof(char s[]);
double exponentiate(int base, int power);

int main() {
  char input[] = "1234567.89e-2";

  printf("The value of atof called on %s is %f\n" , input, extended_atof(input));
}

double extended_atof(char s[]) {
  double val, power, exponent = 1.0;
  int exp_sign, i, sign;

  for (i = 0; isspace(s[i]); i++)  /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i]- '0');
    power *= 10.0;
  }
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    exp_sign = (s[i] == '-') ? -1 : 1;  /* get the sign of the exponent */
    if (s[i] == '-' || s[i] == '+')
      i++;
    for (exponent = 0.0; isdigit(s[i]); i++)
      exponent = exponent * 10.0 + (s[i] - '0');
    printf("The exponent is: %f\n", exponent);
    exponent = exponentiate(10, exponent);
    exponent = (exp_sign == -1) ? 1 / exponent : exponent;
  }
  return (sign * val / power) * exponent;
}

double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)  /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i]- '0');
    power *= 10.0;
  }
  return sign * val / power;
}

/* return base ^ power */
double exponentiate(int base, int power) {
  double ret_val = 1.0;

  while (power-- > 0)
    ret_val = ret_val * base;

  return ret_val;
}


