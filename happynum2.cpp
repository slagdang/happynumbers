
#include <map>

#include "happynum2.h"

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

bool IsHappy2(int num)
{
    std::map<int, int>      calculated;

    if (0 == num)
        return false;

    calculated[num] = 1;

    while (1 != num)
    {
        int         happy = happysummation(num);

        if (calculated.count(happy))
            return false;

        num = happy;
        calculated[num] = 1;
    }

    return true;
}
