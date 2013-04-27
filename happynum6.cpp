#include "happynum.h"

/*
   This version does not store any information about which numbers have been seen before.
   It relies on the fact that the largest path within the closed set can be no longer than
   a finite number of traverses smaller than the closed set. See THEMATH.md for the number.
   If after this number of traverses from within the closed set neither 0 nor 1 has
   been reached, then it will never be reached and failure is detected.
 
   This one took about 0.8 seconds to get to 10,000,000 which is faster than version
   2 which uses a map to remember where it has been. This one uses very little memory.
 */

void InitHappy(void)
{
}

bool IsHappy(int num)
{
    if (0 == num)
        return false;

#if defined(ALLOWNEGINPUT) && ALLOWNEGINPUT
// modulo doesn't work exactly like you think on negative numbers. So go positive.
    if (num < 0)
        num = -num;
#endif

    int countdown = maxtraversalsinset;

    while (countdown > 0 && num != 1)
    {
        if (num < closedsetsize)
            --countdown;

        num = happysummation(num);
    }

    return 1 == num;
}
