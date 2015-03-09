/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int
main(int argc, char *argv[])
{
    // check if the input is valid
    if (argc != 2 && argc != 3)
    {
        printf("Usage: %s n [s]\n", argv[0]);
        return 1;
    }

    // change the first number into int
    int n = atoi(argv[1]);

    // generate the seed
    if (argc == 3)
    {
        // when seed is provided
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        // when seed is not provided
        srand48((long int) time(NULL));
    }

    // generate the n random numbers (less than 65536) and print them
    for (int i = 0; i < n; i++)
        printf("%d\n", (int) (drand48() * LIMIT));

    // that's all folks
    return 0;
}
