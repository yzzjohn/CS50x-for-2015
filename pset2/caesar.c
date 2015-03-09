/******************************************************************************
 *
 * caesar.c
 *
 * HarvardX: CS50x3 Introduction to Computer Science
 * Problem Set 2
 *
 * John YZ Zhu
 * yzzjohn@gmail.com
 *
 * Encypt your message via caesar cipher
 *
 *****************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    // check if the command-line arguments is valid
    if (argc == 2)
    {
        // check if the key is a number
        int x; char y;
        if (sscanf(argv[1], " %d %c", &x, &y) != 1)
        {
            printf("Error! The key should be an integer\n");
            return 2;
        }

        // get the key number
        int k = atoi(argv[1]) % 26;

        // get the plaintext from users
        char *p = GetString();
        int c;

        for (int i = 0, n = strlen(p) ; i < n; i++)
        {
            // do the encryption
            c =  (int) p[i] + k;

            // capital letter
            if ((int) p[i] >= 'A' && (int) p[i] <= 'Z')
            {
                // avoid non-analphabetic character
                if (c > 'Z')
                    c = (char) (c % 'Z' + 'A' - 1);
            }

            // small letter
            else if ((int) p[i] >= 'a' && (int) p[i] <= 'z')
            {

                // avoid non-analphabetic character
                if (c > 'z')
                    c = (char) (c % 'z' + 'a' - 1);
            }

            // non-analphabetic character
            else
                c = p[i];

            printf("%c", c);

        }

        printf("\n");

        // free the heap
        free(p);

        //  return a value of 0 which means success
        return 0;
    }

    else
    {
        // error warning
        printf("Error! Usage: ./caesar number!\n");

        // return a value of 1 which tends to signify an error
        return 1;
    }
}
