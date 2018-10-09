/**
 * CS1010 Semester 1 AY18/19
 * Assignment 2: Collatz 
 *
 * @file: collatz.c
 * @author: Lincoln Lim (Group C1A)
 */

#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

void attempt(long n);
long loop(long n);
long collatz(long n);

int main()
{
	long n = cs1010_read_long();
	attempt(n);
	return 0;
}

void attempt(long n)
{ 
	//we need to find the max and serial number
	long serial = 1;
	long max = 0;

	//create an array to store the number of steps
	long steps[n+1];
	steps[0] = 0;
  
	//key in the values
	for (long i=1; i<=n; i+=1)
	{ 
		steps[i] = loop(i);
	}
  
	//compare them all
	for (long i=1; i<=n; i+=1)
	{ 
		if (steps[i] >= max)
		{ //you want the value
			serial = i;
			max = steps[i];
		} //the rest are useless
	}
  
	//print the results
	cs1010_println_long(serial);
	cs1010_println_long(max);
}

//this function repeats the operation
//returns the number of steps
long loop(long n)
{
	long count = 0;
	while (n>1)
	{
		n = collatz(n);
		count += 1;
	}
	return count;
}

//this function does the collatz operation
//returns the next number in line
long collatz(long n)
{
	if (n%2 == 0)
	{
		return n/2;
	}
	else
	{
		return n*3+1;
	}
}