
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

// This finds the smallest value for which the transformed value is greater than the original value.

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

int main(int argc, const char *argv[])
{
	int			checkit;

	for (checkit = 162; checkit > 1; checkit--)
	{
		int			xform = happysummation(checkit);

		if (xform > checkit)
		{
			std::cout << "The smallest number which produces a value larger than itself is " << checkit
			          << " and it produces the value " << xform << std::endl;
			break;
		}
	}

	return 0;
}
