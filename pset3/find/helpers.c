/******************************************************************************
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 *****************************************************************************/

#include <cs50.h>
#include <math.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

bool
search(int value, int array[], int n)
{
    if (n < 1)
        return false;

    // tear the "book" into half
    int num = n / 2;

    // when smaller than the midpoint
    if (value < array[num] && n != 1)
    {
        // set an array to get the left part
        int leftpart[num];

        for (int i = 0; i < num; i++)
            leftpart[i] = array[i];

        // recursion
        return search(value, leftpart, num);
    }

    // when larger than the midpoint
    else if (value > array[num] && n != 1)
    {
        // when the number of length is odd
        if (n % 2 == 0)
        {
            int rightpart[num];

            for (int i = 0; i < num ; i++)
                rightpart[i] = array[i + num];

            return search(value, rightpart, num);
        }

        // when the number of length is even
        else
        {
            int rightpart[num];

            for (int i = 0; i < num ; i++)
                rightpart[i] = array[i + num + 1];

            return search(value, rightpart, num);
        }
    }

    // breakpoint1 (not matched)
    else if (value != array[num])
        return false;

    // breakpoint2 (matched)
    else
        return true;
}


/**
 * Merge sorts array of n values.
 */

void
merge(int leftpart[], int rightpart[], int results[], int n1, int n2)
{
    // Use two arrow to point the start postion of two arrays
    int start1 = leftpart[0], start2 = rightpart[0], size = n1 + n2;

    for (int i = 0, j = 0, k = 0; k < size; k++)
    {

        // Compare the pointed numbers of two arrays
        if (i < n1 && j < n2)
        {

            // Copy the smaller one
            if (start1 >= start2)
            {
                results[k] = start2;
                start2 = rightpart[j + 1];
                j++;
            }

            else
            {
                results[k] = start1;
                start1 = leftpart[i + 1];
                i++;
            }
        }

        // Copy the rest part of the right array
        else if (i >= n1)
        {
            results[k] = rightpart[j];
            j++;
        }

        // Copy the rest part of the left array
        else if (j >= n2)
        {
            results[k] = leftpart[i];
            i++;
        }
    }
}


/**
 * Sort an array of n values
 */

void
sort(int values[], int n)
{
    // Breakpoint
    if (n < 2)
        return;

    // Get the size of the left part and the right part
    int num1 = n  / 2, num2 = (n + 1) / 2;

    // Divide the array into left and right
    int left[num1], right[num2];

    for (int i = 0; i < num1; i++)
        left[i] = values[i];

    // Sort the left paft
    sort(left, num1);

    for (int i = 0; i < num2; i++)
        right[i] = values[i + num1];

    // Sort the right part
    sort(right, num2);

    // Merge two parts
    merge(left, right, values, num1, num2);
}
