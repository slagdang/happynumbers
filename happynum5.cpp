#include "happynum.h"

/*
   This version maintains an array with a value for every number in the closed set 
   (numbers which can be in loops) whether this number is happy, unhappy or unchecked.
   Numbers outside the closed set are traversed until a number within the closed set (or 1)
   is reached. Once inside the closed set, numbers are traversed further until a loop is
   detected, 1 or 0 is reached or a value which has previously been checked is reached.
   After a result is determined the result is written to all numbers within the closed
   set which were traversed. If a number within the closed set is ever seen twice without
   seeing 1, then failure is detected. Numbers larger than the closed set cannot be seen
   twice in a single happiness check so there is no need to check them for duplication.

   This version takes advantage of the fact that before you enter the closed set you are
   outside it and after you enter it you never leave it in order to eliminate some
   conditionals within the loops.

   This one took about 0.34 seconds to get to 10,000,000. It uses a small amount of RAM.
   It is the fastest so far and may be the fastest linear search method.
 */



// Every non-terminal loop must have at least one step in it which produces an
// transformed values greater than itself. There are no numbers above 162 which produce
// numbers greater than the input so every loop must have at least one number below 163.
// In fact every loop must have at least one number below 100. But every value in a loop
// must be less than 163, so we store the results of all values below 163. Setting ENTIRELOOPSET
// to 0 stores on 100 values which saves some RAM but increases the time to 10M by about 50%.
#define ENTIRELOOPSET 1

#if defined(ENTIRELOOPSET) && ENTIRELOOPSET
// Store every value that can be in a loop.
const int loopitems = closedsetsize;

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
const int loopitems = largestgrower + 1;

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
