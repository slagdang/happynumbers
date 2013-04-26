
#include <map>

#include "happynum3.h"

static int happysummation(int num)
{
    int         sum = 0;

    if (num < 0)
        num = -num;

    while (num != 0)
    {
        int         dig = num % 10;

        sum += dig * dig;
        num /= 10;
    }

    return sum;
}

static std::map<int, int>      happymap3;

bool IsHappy3(int innum)
{
    if (0 == innum)
        return false;

    if (1 == innum)
        return true;

    if (0 != happymap3.count(innum))
    {
        return happymap3[innum];
    }

    int     happied = happysummation(innum);

// mark this number as non-happy in case we loop back to it
    happymap3[innum] = 0;

// then update the number with what we get by checking on it
    return ((happymap3[innum] = IsHappy3(happied))) ? true : false;
}
