#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fib.h"

/*
 *
 *  Generate m Fibonacci numbers and print out the nth one as requested by the user
 *
 *  fibonacci m
 *
 *
 *  If the incorrect number of arguments appear on the command line a help message
 *  is printed and the program exits.
 *
 *  Otherwise:
 *  Internally generates the first m Fibonacci numbers (F[0]..F[m-1] then prompts user
 *  for which Fibonacci number to print and asks if they want to continue.   
 *
 *  It terminates by printing a simple mathematical truth.
 *
 */
 



extern int F[MAX];



// generate the first n Fibonacci numbers in array F
void GenerateFibonacci(int n) {
int i;
F[0] = 0;
F[1] = 1;
for (i = 1; i <= n; i++) {
    F[i+1] = F[i] + F[i-1];
    }
}

