#include "happynum.h"

/*
   This version tries to recognize any looping by remembering the lowest number
   seen so far. If we see this again, we know we are looping. It doesn't work
   because some numbers outside the loop may be bigger than all in the loop and
   thus we just keep looping without detecting we are doing so. It fails on the
   number 2 which contains a loop that does not include the number 2.

   This one never reaches 10,000,000.
 */

void InitHappy(void)
{
}

bool IsHappy(int num)
{
    if (0 == num)
        return false;

// modulo doesn't work exactly like you think on negative numbers. So go positive.
    if (num < 0)
        num = -num;

// lowest is the lowest number we've seen so far while iterating
    int     lowest = num;

    while (1)
    {
        num = happysummation(num);

        if (num == lowest)
            break;

        if (num < lowest)
            lowest = num;
    }

    return 1 == lowest;
}
