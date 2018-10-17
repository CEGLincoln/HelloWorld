/**
 * CS1010 Semester 1 AY18/19
 * Assignment 3: CountingSort
 *
 * Read in a positive integer n and a max value k, followed by
 * a list of n numbers between 1 to k.  Print the numbers in
 * increasing order.
 *
 * @file: countingsort.c
 * @author: Lincoln Lim (Group C1A)
 */
#include "cs1010.h"

int main()
{
	//inputs
	long n = cs1010_read_long();
	long k = cs1010_read_long();
	long* a = cs1010_read_long_array(n);
	
	//declarations
	long c[k+1];
	for (long i=0; i<k+1; i+=1)
	{
		c[i] = 0;
	}
	
	//working it out
	for (long i=0; i<n; i+=1)
	{
		c[a[i]] += 1;
	}
	
	//outputs
	for (long i=1; i<=k; i+=1)
	{
		for (long j=1; j<=c[i]; j+=1)
		{
			cs1010_println_long(i);
		}
	}
	return 0;
}
