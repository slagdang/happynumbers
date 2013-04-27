
#include <map>

#include "happynum.h"

static int happysummation(int num)
{
    int         sum = 0;

//    if (num < 0)
//        num = -num;

    while (num != 0)
    {
        int         dig = num % 10;

        sum += dig * dig;
        num /= 10;
    }

    return sum;
}

const int loopitems = 163;

char happyres[loopitems] =
{
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1
};

void InitHappy(void)
{
    happyres[0] = 0;
    happyres[1] = 1;
}

static bool IsHappyLooper(int innum)
{
    int potentialresult;

    if (-1 != ((potentialresult = happyres[innum])))
        return potentialresult;

    int     happied = happysummation(innum);

// mark this number as non-happy in case we loop back to it
    happyres[innum] = 0;

// then update the number with what we get by checking on it
    bool         rethappy = IsHappyLooper(happied);

    happyres[innum] = rethappy;

    return rethappy;
}

static bool IsHappyBigUn(int innum)
{
    int     happied = happysummation(innum);

// mark this number as non-happy in case we loop back to it
    bool    rethappy = happied < loopitems ? IsHappyLooper(happied) : IsHappyBigUn(happied);

    return rethappy;
}

bool IsHappy(int innum)
{
    return innum < loopitems ? IsHappyLooper(innum) : IsHappyBigUn(innum);
}
