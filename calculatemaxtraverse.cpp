#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <map>

#include "happynum.h"

/*
   This version creates an empty map each time a new number is tested. It records
   every number traversed into this map. If a number is seen twice before reaching
   1, then failure is detected.

   This variant records the length of each traversal.
 */

int TraversalLengthHappy(int num)
{
    int         traverselength = 1;
    std::map<int, bool>      calculated;

    calculated[num] = true;

    while (1 != num && 0 != num)
    {
        num = happysummation(num);
        traverselength++;

        if (0 != calculated.count(num))
            break;

        calculated[num] = true;
    }

    return traverselength;
}

int main(int argc, const char *argv[])
{
    int         lp;
    int         maxtraverse = 0;

    for (lp = 0; lp < closedsetsize; lp++)
    {
        int         traverse = TraversalLengthHappy(lp);

        if (traverse > maxtraverse)
            maxtraverse = traverse;
    }

    std::cout << "The largest traverse is " << maxtraverse << "." << std::endl;

    return 0;
}
