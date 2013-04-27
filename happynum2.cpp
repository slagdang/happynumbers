#include <map>

#include "happynum.h"

/*
   This version creates an empty map each time a new number is tested. It records
   every number traversed into this map. If a number is seen twice before reaching
   1, then failure is detected.

   This one took about 29 seconds to get to 10,000,000.
 */

void InitHappy(void)
{
}

bool IsHappy(int num)
{
    std::map<int, bool>      calculated;

    if (0 == num)
        return false;

    calculated[num] = true;

    while (1 != num)
    {
        int         happy = happysummation(num);

        if (calculated.count(happy))
            return false;

        num = happy;
        calculated[num] = true;
    }

    return true;
}
