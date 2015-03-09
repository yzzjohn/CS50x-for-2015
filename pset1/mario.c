/******************************************************************************
 *
 * mario.c
 *
 * HarvardX: CS50x3 Introduction to Computer Science
 * Problem Set 1
 *
 * John YZ Zhu
 * yzzjohn@gmail.com
 *
 * Itsa Mario!
 *
 *****************************************************************************/

#include <cs50.h>
#include <stdio.h>

bool CheckInput(int height);
void DrawChart(int height);

int
main(void)
{
    int h;

    // initialize a flag
    bool flag = false;

    // keep asking for input until it's vaild
    do
    {
        // ask for the height
        printf("height: ");

        // record users' input
        h = GetInt();

        // check the input
        flag = CheckInput(h);
    }
    while (flag == false);

    // draw the chart
    DrawChart(h);

    return 0;
}


/**
 * Check if users' input is between 0 and 23
 */

bool
CheckInput(int height)
{
    if (height < 0 || height > 23)
        return false;

    else
        return true;
}


/**
 * Draw the chart according to users' input
 */

void
DrawChart(int height)
{
    for (int i = 0; i < height; i++)
    {
        // draw the blank
        for (int j = 1; j < height - i; j++)
            printf(" ");

        // draw the "#"
        for (int k = 1; k <= i + 2; k++)
            printf("#");

        printf("\n");
    }
}
