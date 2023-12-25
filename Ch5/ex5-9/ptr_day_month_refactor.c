/* Rewrite the routines day_of_year and month_day with pointers instead of indexing. */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
  int month, day, dayofyear = 365, year = 1883;

  printf("What day of what month was day %d of %d?\n", dayofyear, year);
  month_day(year, dayofyear, &month, &day);
  printf("Day: %d, Month: %d\n", day, month);

  printf("What day of the year was on day %d of month %d of year %d?\n", day, month, year);
  dayofyear = day_of_year(year, month, day);
  printf("Day %d\n", dayofyear);

}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* I think the nicest thing to do is to split out indexing of the form daytab[a][b] into two steps, as that avoids having to keep
 * track of the type of pointer that we are manipulating with each operation in a complicated expression.  For example,
 * daytab is a pointer to an array of 13 chars, so (daytab + 1) jumps 13 chars along to the start of the second array of 13 chars,
 * and *daytab gives us a pointer to a char, since *daytab is 'an array of 13 chars, and in c arrays' values are pointers to the
 * first elt of the array. That means that in expressions like *(*(daytab + leap) + n), to obtain the number of days in some month,
 * we need to keep track of what daytab is and what *daytab is, and that is potentially confusing.
 *
 * Simpler would be to define an intermediate pointer to char, p = *(daytab + leap), which gives us a convenient handle on the array
 * of month day lengths that we want to use for a given year.  We can then access the number of days of month n of a given year
 * with *(p + n), which is far simpler and easier to reason about in expressions.

/* day_of_year: set day of year from month & day. */
int day_of_year(int year, int month, int day) {
  int i, leap;

  if (year <= 0) {
    printf("Please provide a positive numbered year.\n");
    return -1;
  } else if (month < 1 || month > 12) {
    printf("Please provide a month number between 1 and 12.\n");
    return -1;
  }

  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  char *p = *(daytab + leap);
  if (day < 1 || day > *(p + month))
    printf("Please provide a day that is actually in the specified month.\n");
  for (i = 1; i < month; i++)
    day += *(p + i);
  return day;
}

/* month_day: set month, day from day of year. */
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  if (yearday < 1) {
    printf("Please provide a positive number of days\n");
    return;
  } else if (year < 0) {
    printf("Please provide a non-negative year.\n");
    return;
  }

  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  char *p = *(daytab + leap);
  for (i = 1; yearday > *(p + i) && i < 13; i++)
    yearday -= *(p + i); /* This works but is quite ugly, better to split it out. */
  if (i >= 13) {
    printf("Please provide a number of days that fits within the specified year\n");
    *pmonth = -1;
    *pday = -1;
  } else {
  *pmonth = i;
  *pday = yearday;
  }
}
