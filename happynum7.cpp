#include "happynum.h"

#define ALLOWNEGINPUT 0

const int closedsetsize = 163;
const int maxtraversalsinset = 107;

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

void InitHappy(void)
{
}

bool IsHappyLooper(int num)
{
    int countdown = maxtraversalsinset;

    while (countdown > 0 && num != 1)
    {
        --countdown;

        num = happysummation(num);
    }

    return 1 == num;
}

bool IsHappyBigUn(int num)
{
    while (num >= closedsetsize)
    {
        num = happysummation(num);
    }

    return IsHappyLooper(num);
}

bool IsHappy(int innum)
{
#if defined(ALLOWNEGINPUT) && ALLOWNEGINPUT
    if (innum < 0)
        innum = -innum;
#endif

//    return innum < closedsetsize ? IsHappyLooper(innum) : IsHappyBigUn(innum);
    return IsHappyBigUn(innum);
}
