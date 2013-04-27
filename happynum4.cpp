#include <map>

#include "happynum.h"

/*
   This version maintains a map for every checked number in the closed set (numbers which can
   be in loops) whether this number is happy or not. Numbers outside the closed set are
   traversed until a number within the closed set (or 1) is reached. At
   each traversal this map is checked to see if we already know the result for this value.
   If a number within the closed set is ever seen twice without seeing 1, then failure is
   detected. Numbers larger than the closed set cannot be seen twice so there is no need
   to check them. Happiness of nubmers within the closed set it recorded in the map after
   it is determined.

   This one took about 1.2 seconds to get to 10,000,000.
 */

static std::map<int, bool>      happymap;

void InitHappy(void)
{
    happymap[0] = 0;
    happymap[1] = 1;
}

bool IsHappy(int innum)
{
#if defined(ALLOWNEGINPUT) && ALLOWNEGINPUT
    if (innum < 0)
        innum = -innum;
#endif

    if (0 != happymap.count(innum))
    {
        return happymap[innum];
    }

    int     happied = happysummation(innum);

// mark this number as non-happy in case we loop back to it
    if (innum < closedsetsize)
        happymap[innum] = false;

// then update the number with what we get by checking on it
    bool         rethappy = IsHappy(happied);

    if (innum < closedsetsize)
        happymap[innum] = rethappy;

    return rethappy;
}
