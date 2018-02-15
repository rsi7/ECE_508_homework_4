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


int one;
int F[MAX];
int two;

extern void GenerateFibonacci(int n);


int main(int argc, char ** argv) {
int i;
int n;
int m;
char Answer[120];
one  = 1;
two  = 2;

// if single argument then use that as the number of Fibonacci numbers to generate
// otherwise, print message on usage  
if (argc = 2) {
    m = atoi(argv[2]);
    if (m > MAX) {
        fprintf(stderr, "I can't generate more than the first %0d Fibonacci numbers\n",MAX);
        exit(1);
    }
    GenerateFibonacci(m);
    do {
        fprintf(stdout, "Print which Fibonacci number? ");
        scanf("%d", n);
        if (n > m-1) {
            fprintf(stderr, "I can't print more than the first %0d Fibonacci numbers\n",m);
            exit(1);
            }
        fprintf(stdout,"Fibonacci number %0d = %d\n",n,F[n]);
        fprintf(stdout,"Quit? ");
        scanf("%s", Answer);
        }
    while (!strcmp(Answer,"no"));

    fprintf(stdout, "one times two = %0d\n",one * two);
    }

else {
    fprintf(stderr, "usage:  fibonacci m\n\nwhere m is how many Fibonacci numbers to create\n");
    }
}
