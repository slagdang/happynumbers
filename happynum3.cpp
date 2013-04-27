#include <map>

#include "happynum.h"

/*
   This version maintains a map which indicates for every number ever checked whether
   it is happy or not. At each traversal this map is checked to see if we already know
   the result for this value. If a number is ever seen twice without seeing 1, then
   failure is detected.

   This one took about 10 seconds to get to 10,000,000. It uses a lot of RAM too.
 */

static std::map<int, bool>      happymap;

void InitHappy(void)
{
    happymap[0] = 0;
    happymap[1] = 1;
}

bool IsHappy(int innum)
{
    if (0 != happymap.count(innum))
    {
        return happymap[innum];
    }

    int     happied = happysummation(innum);

// mark this number as non-happy in case we loop back to it
    happymap[innum] = false;

// then update the number with what we get by checking on it
    bool         rethappy = IsHappy(happied);

    happymap[innum] = rethappy;

    return rethappy;
}
