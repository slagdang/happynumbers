#ifndef _H_HAPPYNUM3
#define _H_HAPPYNUM3

#pragma once

// Do we allow negative numbers as input? Not needed for test, but maybe for completeness.
#define ALLOWNEGINPUT 0

void InitHappy(void);
bool IsHappy(int num);

static const int closedsetsize = 163;
static const int largestgrower = 99;
static const int maxtraversalsinset = 19;

static int happysummation(int num)
{
    int         sum = 0;

    while (num != 0)
    {
        int         dig = num % 10;

        sum += dig * dig;
        num /= 10;
    }

    return sum;
}

#endif
