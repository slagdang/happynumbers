
#include <map>

#include "happynum.h"

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

void InitHappy(void)
{
    happymap3[0] = 0;
    happymap3[1] = 1;
}

bool IsHappy(int innum)
{
    if (0 != happymap3.count(innum))
    {
        return happymap3[innum];
    }

    int     happied = happysummation(innum);

// mark this number as non-happy in case we loop back to it
	if (innum < 163)
	    happymap3[innum] = 0;

// then update the number with what we get by checking on it
	int			rethappy = IsHappy(happied);

	if (innum < 163)
		happymap3[innum] = rethappy;

    return rethappy ? true : false;
}
