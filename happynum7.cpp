#include "happynum.h"

/*
   This version does not store any information about which numbers have been seen before.
   It relies on the fact that the largest path within the closed set can be no longer than
   a finite number of traverses smaller than the closed set. See THEMATH.md for the number.
   107 traverses. If after this number of traverses from within the closed set neither 0 nor
   1 has been reached, then it will never be reached and failure is detected. This is similar
   to version 6, but it take advantage of the fact until you enter the closed set you are
   outside it and after you enter it you never leave it to eliminate some conditionals
   within the loops. This did not improve speed significantly versus version 6.
 
   This one took about 0.8 seconds to get to 10,000,000 which is faster than version
   2 which uses a map to remember where it has been. This one uses very little memory.
 */

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
