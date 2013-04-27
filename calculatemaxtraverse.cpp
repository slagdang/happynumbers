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

static int TraversalLengthHappy(int num)
{
    int         traverselength = 0;
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

    return (1 == num) ? traverselength : 0;
}

static int TraversalLengthAny(int num)
{
    int         traverselength = 0;
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
    int         maxtraversehappy = 0;
    int         maxtraverseany = 0;

    for (lp = 0; lp < closedsetsize; lp++)
    {
        int         traversehappy = TraversalLengthHappy(lp);
        int         traverseany = TraversalLengthAny(lp);

        if (traversehappy > maxtraversehappy)
            maxtraversehappy = traversehappy;
        if (traverseany > maxtraverseany)
            maxtraverseany = traverseany;
    }

    std::cout << "The longest traverse is " << maxtraverseany << "." << std::endl;
    std::cout << "The longest traverse to 1 is " << maxtraversehappy << "." << std::endl;

    return 0;
}
