/******************************************************************************
 *
 * vigenere.c
 *
 * HarvardX: CS50x3 Introduction to Computer Science
 * Problem Set 2
 *
 * John YZ Zhu
 * yzzjohn@gmail.com
 *
 * Encrypt your message via vigenera algorithom
 *
 *****************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype of funcitons
bool check_argument(int num, char *kword[]);

int
main(int argc, char *argv[])
{
    // check if the input is vaild
    bool check = check_argument(argc, argv);

    // do the encryption
    if (check == true)
    {
        // get the plaintext from users
        char *p = GetString();

        // copy the password from users
        char *key = argv[1];

        int n = strlen(key);
        char c;

        // change the word into integer
        for (int k = 0; k < n; k++)
        {
            // capital letter
            if ((int) key[k] <= 'Z')
                key[k] -= 'A';

            // small letter
            else
                key[k] -= 'a';
        }

        for (int i = 0, n1 = strlen(p), arrow = 0; i < n1; i++)
        {
            // point out the true key's position
            int I = arrow % n;

            // capital letter
            if (p[i] >= 'A' && p[i] <= 'Z')
            {
                int encryption = p[i] + key[I];

                // make sure the output is alphabetic letter
                if (encryption > 'Z')
                    c = (char) (encryption % 'Z' + 'A' - 1);
                else
                    c = (char) encryption;

                 printf("%c", c);
                 arrow ++;
            }

            // small letter
            else if (p[i] >= 'a' && p[i] <= 'z')
            {
                int encryption = p[i] + key[I];

                if (encryption > 'z')
                    c = (char) (encryption % 'z' + 'a' - 1);
                else
                    c = (char) encryption;

                printf("%c", c);
                arrow ++;
            }

            // non-alphabetic character
            else
            {
                c = p[i];
                printf("%c",c);
            }
        }

        printf("\n");

        // free the heep
        free(p);
    }

    // complain about the invaild input
    else
    {
        printf("Error!\n");

        // return a non-zero value which means error
        return 1;
    }
}


/**
 * The function aims to tese if the users' input is valid.
 */

bool
check_argument(int num, char *kword[])
{
    if (num == 2)
    {
        for (int i = 0, n =strlen(kword[1]); i < n; i++)
        {
            int test = (int) kword[1][i];

            // judge if the keyword is valid
            if ((test < 'A' || test > 'Z') && (test < 'a' || test > 'z'))
                return false;
        }

        return true;
    }

    // when input more than one or no command-line arguments
    else
        return false;
}
