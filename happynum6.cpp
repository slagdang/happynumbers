
#include "happynum.h"

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

bool IsHappy(int num)
{
    if (0 == num)
        return false;

// modulo doesn't work exactly like you think on negative numbers. So go positive.
    if (num < 0)
        num = -num;

	int countdown = maxtraversalsinset;

	while (countdown > 0 && num != 1)
	{
		if (num < closedsetsize)
			--countdown;

		num = happysummation(num);
	}

    return 1 == num;
}
