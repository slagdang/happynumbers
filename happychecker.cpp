
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

#include "happynum.h"

#define HAPPYINIT InitHappy
#define HAPPYCHECK IsHappy

const int maxnum = 10000000;

int main(int argc, const char *argv[])
{
	int				nums;
	int				numhappynums = 0;

	InitHappy();

	for (nums = 0; nums <= maxnum; nums++)
	{
		numhappynums += HAPPYCHECK(nums);
//		std::cout << nums << " " << (IsHappy3(nums) ? "is" : "isn\'t") << " happy" << std::endl;
	}

	std::cout << "There are " << numhappynums << " happy nums between 0 and " << maxnum << " inclusive." << std::endl;
	std::cout << "Should be 1418854." << std::endl;

	return 0;
}

//		printf("%d %s happy.\n",nums,IsHappy1(nums) ? "is" : "isn\'t");
