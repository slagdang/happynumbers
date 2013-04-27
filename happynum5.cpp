#include "happynum.h"

// Every non-terminal loop must have at least one step in it which produces an
// transformed values greater than itself. There are no numbers above 162 which produce
// numbers greater than the input so every loop must have at least one number below 163.
// In fact every loop must have at least one number below 100. But every value in a loop
// must be less than 163, so we store the results of all values below 163.
#define ENTIRELOOPSET 1

// Do we allow negative numbers as input? Not needed for test, but maybe for completeness.
#define ALLOWNEGINPUT 0

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

#if defined(ENTIRELOOPSET) && ENTIRELOOPSET
// Store every value that can be in a loop.
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
#else
const int loopitems = 100;

char happyres[loopitems] =
{
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};
#endif

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

// store result so we don't calculate it again.
    happyres[innum] = rethappy;

    return rethappy;
}

static bool IsHappyBigUn(int innum)
{
    int     happied = happysummation(innum);

    bool    rethappy = happied < loopitems ? IsHappyLooper(happied) : IsHappyBigUn(happied);

    return rethappy;
}

bool IsHappy(int innum)
{
#if defined(ALLOWNEGINPUT) && ALLOWNEGINPUT
    if (innum < 0)
        innum = -innum;
#endif

    return innum < loopitems ? IsHappyLooper(innum) : IsHappyBigUn(innum);
}
