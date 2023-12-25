/* There is no error checking of day_of_year or month_day.  Remedy this defect. */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
  int month, day, dayofyear = 366, year = 1884;

  printf("What day of what month was day %d of %d?\n", dayofyear, year);
  month_day(year, dayofyear, &month, &day);
  printf("Day: %d, Month: %d\n", day, month);
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day. */
int day_of_year(int year, int month, int day) {
  int i, leap;

  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  for (i = 1; i< month; i++)
    day += daytab[leap][i];
  return day;
}

/* month_day: set month, day from day of year. */
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  if (yearday < 1) {
    printf("Please provide a positive number of days\n");
    return;
  }
  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  for (i = 1; yearday > daytab[leap][i] && i < 14; i++)
    yearday -= daytab[leap][i];
  if (i >= 14) {
    printf("Please provide a number of days that fits within the specified year\n");
  }
  *pmonth = i;
  *pday = yearday;
}
