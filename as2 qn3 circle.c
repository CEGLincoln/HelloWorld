/**
 * CS1010 Semester 1 AY18/19
 * Assignment 2: Circle
 *
 * @file: circle.c
 * @author: Lincoln Lim (Group C1A)
 */

#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

int main()
{
	/*inputs*/
	long r = cs1010_read_long();
	//center is (r,r)
	
	/*canvas*/
	double d[2*r+1][2*r+1];
	
	/*find distance*/
	for (long y=0 ; y < (2*r+1) ; y+=1)
	{
		for (long x=0 ; x < (2*r+1) ; x+=1)
		{
			d[x][y] = sqrt(pow(labs(x-r),2) + pow(labs(y-r),2));
		}
	}
	
	/*the circle*/
	for (long y=0 ; y < (2*r+1) ; y+=1)
	{
		for (long x=0 ; x < (2*r+1) ; x+=1)
		{
			if (fabs(d[x][y]-r) < 0.1)
			{
				printf("@");
			}
			else if (fabs(d[x][y]-r) < 0.3)
			{
				printf("O");
			}
			else if (fabs(d[x][y]-r) < 0.5)
			{
				printf("*");
			}
			else if (fabs(d[x][y]-r) < 0.7)
			{
				printf("+");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	/*outputs*/
	return 0;
}