
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

const int checknums = 163;

int main(int argc, const char *argv[])
{
	int				checkit;
	int				sum[checknums];
	int				biggestsofar = 0;
	int				xformbound = 0;
	int				xform;

	for (checkit = (checknums - 1); checkit >= 0; checkit--)
	{
		int	xform = happysummation(checkit);

		sum[checkit] = xform;

		if (0 == xformbound && xform > checkit)
		{
			std::cout << "The smallest number which produces a value larger than itself is " << checkit
			          << " and it produces the value " << xform << std::endl;
			xformbound = xform;
		}
	}

// now find the biggest number that is transformed from 0 the found smallest
	for (checkit = 2; checkit <= checknums; checkit++)
	{
		if (sum[checkit] > biggestsofar)
			biggestsofar = sum[checkit];

		if (biggestsofar <= checkit)
		{
			std::cout << "Every transformed number below " << checkit << " is less than or equal to " << checkit << std::endl;
			break;
		}
	}

	return 0;
}
