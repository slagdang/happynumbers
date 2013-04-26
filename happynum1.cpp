
#include "happynum1.h"

bool IsHappy1(int num)
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
        int         numd = num;
        int         sum = 0;

        while (numd > 0)
        {
            int         dig = numd % 10;

            sum += dig * dig;
            numd /= 10;
        }

        num = sum;

        if (num == lowest)
            break;

        if (num < lowest)
            lowest = num;
    }

    return 1 == lowest;
}
