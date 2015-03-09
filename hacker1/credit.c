/***************************************************************************
 *
 * credit.c
 *
 * HarvardX: CS50x3 Introduction to Computer Science
 * Problem Set 1, Hacker Edition
 *
 * John YZ Zhu
 * yzzjohn@gmail.com
 *
 * check if the give number belongs to AMEX, VISA, MASTERCARD or invalid
 *
 **************************************************************************/

#include <cs50.h>
#include <stdio.h>

void name(long long);
int check(long long);

int
main(void)
{
    // ask for input
    printf("Number: ");
    long long num = GetLongLong();

    // judge if the input is valid
    while (num < 0)
    {
        printf("Retry: ");
        num = GetLongLong();
    }

    // caculate the sum
    check(num);

    // judge the sort in positive situation
    if (check(num)% 10 == 0)
        name(num);

    // negative situation
    else
        printf("INVALID\n");

    return 0;
}


/**
 * Check which kind of card is according to the number provided
 */

void
name(long long num)
{
    int i = 0;
    long long num_test = num;

    // calculate the unit amount
    while (num_test > 0)
    {
        num_test /= 10;
        i++;
    }

    // mastercard of visa
    if (i == 16)
    {
        int test = num / 1000000000000000;

        // mastercard
        if (test == 5)
            printf("MASTERCARD\n");

        // visa
        else if (test == 4)
            printf("VISA\n");
    }

    // american express
    else if (i == 15)
    {
        int test = num / 10000000000000;

        // AMEX
        if (test == 34 || test == 37)
            printf("AMEX\n");

        // INVALID
        else
            printf("INVALID\n");
    }

    // visa
    else if (i == 13)
    {
        int test = num / 1000000000000;

        if (test == 4)
            printf("VISA\n");

        else
            printf("INVALID\n");
    }

    // INVALID
    else
        printf("INVALID\n");
}


/**
 * Check if the number provided is valid
 */

int
check(long long num)
{
    int sum = 0;

    // set flag to distinguish the digits of different position
    bool flag = false;

    // calculate the sum
    while (num > 0)
    {
        // get the "units" digit
        int digit = num % 10;

        // algorithm for digits on the even unit
        if (flag == true)
        {
            digit *= 2;

            // in case the production is double
            if (digit >= 10)
            {
                sum += digit % 10;
                digit /=  10;
                sum += digit;
                flag = false;
            }

            else
            {
                sum += digit;
                flag = false;
            }
        }

        // algorithm for digits on the odd unit
        else
        {
            sum += digit;
            flag = true;
        }

        // preparation for getting the next digit
        num /= 10;
    }

    return sum;
}
