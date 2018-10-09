/**
 * CS1010 Semester 1 AY18/19
 * Assignment 1: Taxi
 * Read the day, hour, and minute when a passenger board a taxi
 * and the distance in meter travelled from the standard input,
 * and print the taxi fare to the standard output.
 * @file: taxi.c
 * @author: Lincoln Lim (Group C1A)
 */
#include <stdbool.h>
#include "cs1010.h"
#include <math.h>

bool weekday(long day);
bool morning(long hrs,long min);
bool evening(long hrs);
bool midnight(long hrs);
double fare(long dis);
double charge(long day,long hrs,long min,long dis);

int main()
{
	long day = cs1010_read_long();
	long hrs = cs1010_read_long();
	long min = cs1010_read_long();
	long dis = cs1010_read_long();
	cs1010_println_double(charge(day,hrs,min,dis));
	return 0;
}

bool weekday(long day)
{
	//Is it a weekday?
	if (day<=5) return true;
	else return false;
}

bool morning(long hrs,long min)
{
	//Is it morning?
	if ((hrs==9) && (min<30)) return true;
	else if ((6<=hrs) && (hrs<=8)) return true;
	else return false;
}

bool evening(long hrs)
{
	//Is it evening?
	if ((18<=hrs) && (hrs<=23)) return true;
	else return false;
}

bool midnight(long hrs)
{
	//Is it midnight?
	if ((0<=hrs) && (hrs<=5)) return true;
	else return false;
}

double fare(long dis)
{
	//Fare based on distance
	if (dis<=1000) return 3.4;
	else if (dis<=10200) return 3.4 + (0.22*ceil((dis-1000.0)/400.0));
	else return 3.4 + (0.22*23.0) + (0.22*ceil((dis-10200.0)/350.0));
}

double charge(long day,long hrs,long min,long dis)
{
	if (weekday(day) && morning(hrs,min)) return fare(dis)*1.25;
	else if (evening(hrs)) return fare(dis)*1.25;
	else if (midnight(hrs)) return fare(dis)*1.5;
	else return fare(dis);
}