/**
 * CS1010 Semester 1 AY18/19
 * Assignment 2: Weekday
 *
 * @file: weekday.c
 * @author: Lincoln Lim (Group C1A)
 */

#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

/**
 * Read in a year and prints out if the input year is a leap year.
 * @file: leap.c
 * @author: Lincoln Lim (Group C1A)
 * #include <stdbool.h>
 * #include "cs1010.h"
 */
bool is_leap_year(long year)
{
	if (year%4 == 0) {
		if (year%100 == 0) {
			if (year%400 == 0) {
				return true;
			} else {
				return false;
			}
		} else {
			return true;
		}
	} else {
		return false;
	}
}

/**
 * Read in a month and a day and prints the number of days since the beginning of the year.
 * @file: days.c
 * @author: Lincoln Lim (Group C1A)
 * #include "cs1010.h"
 */
long t(long m,long d)
{
	long t = 0;
	switch(m)
	{
		case 1: t=0; break;
		case 2: t=31; break;
		case 3: t=31+28; break;
		case 4: t=31+28+31; break;
		case 5: t=31+28+31+30; break;
		case 6: t=31+28+31+30+31; break;
		case 7: t=31+28+31+30+31+30; break;
		case 8: t=31+28+31+30+31+30+31; break;
		case 9: t=31+28+31+30+31+30+31+31; break;
		case 10: t=31+28+31+30+31+30+31+31+30; break;
		case 11: t=31+28+31+30+31+30+31+31+30+31; break;
		case 12: t=31+28+31+30+31+30+31+31+30+31+30; break;
		default: cs1010_println_string("INVALID MONTH");
	}
	return (t+d);
}

/*find the total of days in the previous years*/
long days(long year)
{
	long dayz = 0;
	if (year>1900)
	{
		for (long y=1900; y<year; y+=1)
		{
			if (is_leap_year(y))
			{
				dayz += 366;
			}
			else
			{
				dayz += 365;
			}
		}
	}
	return dayz;
}

/*day of the week*/
void week(long dayz)
{
	switch (dayz%7)
	{
		case 1: cs1010_println_string("Monday"); break;
		case 2: cs1010_println_string("Tuesday"); break;
		case 3: cs1010_println_string("Wednesday"); break;
		case 4: cs1010_println_string("Thursday"); break;
		case 5: cs1010_println_string("Friday"); break;
		case 6: cs1010_println_string("Saturday"); break;
		case 0: cs1010_println_string("Sunday"); break;
		default: cs1010_println_string("ERROR");
	}
}

/*========== MAIN FUNCTION ==========*/

int main() 
{
	/*inputs*/
	long year = cs1010_read_long();
	long month = cs1010_read_long();
	long day = cs1010_read_long();
	
	/*functions*/
	long dayz = 0;
	dayz += days(year);
	dayz += t(month,day);
	week(dayz);

	/*outputs*/
	return 0;
}