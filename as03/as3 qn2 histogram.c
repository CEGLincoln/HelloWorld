/**
 * CS1010 Semester 1 AY18/19
 * Assignment 3: Histogram
 *
 * Read in a positive integer n followed by n real numbers. 
 * Draw the histogram of the numbers on the stndard output.
 *
 * @file: histogram.c
 * @author: Lincoln Lim (Group C1A)
 */

#include "cs1010.h"
#include <math.h>

#define NUM_OF_BUCKETS 10
#define MAX_SCORE 100
#define BLOCK "█"
#define HALF_BLOCK "▌"

void draw_histogram(double l[])
{
	char *axis_labels[NUM_OF_BUCKETS] = {
		"  0 - 10  ",
		" 10 - 20  ",
		" 20 - 30  ",
		" 30 - 40  ",
		" 40 - 50  ",
		" 50 - 60  ",
		" 60 - 70  ",
		" 70 - 80  ",
		" 80 - 90  ",
		" 90 - 100 ",
	};

	cs1010_println_string("          ┴┴┴┴┴┴┴┴┴┴");

	for (long i = 0; i < NUM_OF_BUCKETS; i += 1) {
		cs1010_print_string(axis_labels[i]);

		// TODO(by student) print your histogram here.
		//cs1010_print_double(l[i]);
		
		while (l[i] != 0) {
			if (l[i] > 1) {
				cs1010_print_string(BLOCK);
				l[i] -= 1;
			} else if (l[i] > 0.5) {
				cs1010_print_string(BLOCK);
				l[i] = 0;
			} else {
				cs1010_print_string(HALF_BLOCK);
				l[i] = 0;
			}
		}
		
		cs1010_println_string("");
	}
}

int main()
{
	//inputs
	long n = cs1010_read_long();
	double* real = cs1010_read_double_array(n);
	
	//declarations
	long b[10] = {0,0,0,0,0,0,0,0,0,0};
	double k[10];
	double l[10];
	
	//figuring it out
	for (long i=0; i<n; i+=1) {
		if (real[i] == 100) {
			b[9] += 1;
		} else {
			b[(int)floor(real[i]/10)] += 1;
		}
	}
	
	for (long i=0; i<10; i+=1) {
		k[i] = (double) b[i]/n*100;
	}
	
	for (long i=0; i<10; i+=1) {
		l[i] = k[i]/10;
	}

	draw_histogram(l);
	return 0;
}
