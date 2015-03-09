/******************************************************************************
 *
 * initials.c
 *
 * HarvardX: CS50x3 Introduction to Computer Science
 * Problem Set 2
 *
 * John YZ Zhu
 * yzzjohn@gmail.com
 *
 * Initialize the name you inputted
 *
 *****************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// global variable
char *name;

// prototype
bool check(void);
void initials(void);

int
main(void)
{
    // ask for input until valid
    do
        name = GetString();
    while (check() == false);

    // initialize the name and output the answer
    initials();

    // free the heep
    free(name);

    return 0;
}


/**
 * Initialize the name and output it
 */

void
initials(void)
{
    char c;

    for (int i = 0; i < strlen(name); i++)
    {
        // initial at the beginning, after space, "-" or "'"
        if (i == 0 || name[i-1] == 32 || name[i-1] == 39 || name[i-1] == '-')
        {
            // when capital character
            if (name[i] >= 'A' && name[i] <= 'Z')
                c = name[i];

            // when small character
            else
                c = name[i] - 32;

            // output
            printf("%c", c);
        }
    }

    printf("\n");
}


/**
 * Ensure no non-analphabetic character except for "-", " ", "." and "'"
 */

bool
check(void)
{
    for (int i = 0; i < strlen(name); i++)
    {
        // character small than "a" except "-", " ", "." and "'"
        if (name[i] < 'A' && name[i] != 32 & name[i] != 39 && name[i] != '-'
                && name[i] != '.')
        {
            printf("You must be kidding me, pleas retry: \n");
            return false;
        }

        // character between "z" and "A"
        else if (name[i] > 'Z' && name[i] < 'a')
        {
            printf("You must be kidding me, pleas retry: \n");
            return false;
        }

        // character larger than "Z"
        else if (name[i] > 'z')
        {
            printf("You must be kidding me, pleas retry: \n");
            return false;
        }
    }

    return true;
}

