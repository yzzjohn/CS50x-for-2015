/******************************************************************************
 *
 * greedy.c
 *
 * HarvardX: CS50x3 Introduction to Computer Science
 * Problem Set 1
 *
 * John YZ Zhu
 * yzzjohn@gmail.com
 *
 * Time for Change
 *
 *****************************************************************************/

#include<cs50.h>
#include<math.h>
#include<stdio.h>

int money;
bool check(int money);
int charge(int money);

int
main(void)
{
    // ask for the input for the first time
    printf("O hai! How much is owned?\n");

    // set a flag for checking input
    bool flag = false;

    do
    {
        float money_raw = GetFloat();

        // change dollar into cents
        money = round(money_raw * 100);

        // stop looping when valid
        if (money > 0)
            flag = true;

        // ask for anpter input when invalid
        else
        {
            printf("Er...How much is owned?\n");
            flag = false;
        }
    }
    while (flag == false);

    // caculate the number of coins
    int number = charge(money);

    // output the answer
    printf("%d\n", number);

    return 0;
}


/*
 * Calculate how many coins are needed by using greedy algorithm
 */

int
charge(int money)
{
    // initialize the number as zero
    int number = 0;

    while (money > 0)
    {
        // quarters
        if (money >= 25)
        {
            number = money / 25 + number;
            money = money % 25;
        }

        // dime
        else if (money >= 10 && money < 25)
        {
            number = money / 10 + number;
            money = money % 10;
        }

        // nickel
        else if ( money >= 5 && money < 10)
        {
            number = money / 5 + number;
            money = money % 5;
        }

        // penny
        else
        {
            number = money / 1 + number;
            money = money % 1;
        }
    }

    return number;
}
