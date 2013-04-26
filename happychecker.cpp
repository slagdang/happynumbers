
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

#include "happynum1.h"
#include "happynum2.h"
#include "happynum3.h"

const int maxnum = 10000;

int main(int argc, const char *argv[])
{
	int				nums;

	for (nums = 0; nums <= maxnum; nums++)
	{
		std::cout << nums << " " << (IsHappy3(nums) ? "is" : "isn\'t") << " happy" << std::endl;
	}

	return 0;
}

//		printf("%d %s happy.\n",nums,IsHappy1(nums) ? "is" : "isn\'t");
