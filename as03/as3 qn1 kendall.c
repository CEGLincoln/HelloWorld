/**
 * CS1010 Semester 1 AY18/19
 * Assignment 3: Kendall
 *
 * Read in a positive integer n and a permutation of numbers 
 * 1..n.  Print the normalized Kendall tau distance.
 *
 * @file: kendall.c
 * @author: Lincoln Lim (Group C1A)
 */
#include "cs1010.h"

int main()
{
	long len = cs1010_read_long();
	long* rank = cs1010_read_long_array(len);

	// TODO(by student) to be completed.
	long count = 0;
	long pairs = 0;
	
	for (long i=0; i<len-1; i+=1)
	{
		for (long j=i+1; j<len; j+=1)
		{
			pairs += 1;
			if (rank[i] > rank[j])
			{
				count += 1;
			}
		}
	}
	cs1010_println_double((double) count/pairs);
	return 0;
}
