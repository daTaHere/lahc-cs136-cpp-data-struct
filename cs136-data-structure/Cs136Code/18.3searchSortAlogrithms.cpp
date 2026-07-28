#include <iostream>
#include "18.3searchSortAlgorithems.h"

using namespace std;

void Test18_3() {
	int nums[] = { 45, 78, 23, 12, 63, 90, 38,  56,  88, 15 };
	int len = sizeof(nums) / sizeof(nums[0]);

	int target = 5;
	int result = seqOrdSearch(nums, len, target);

	result != -1 ? cout << target << " found at position " << result << endl : cout << target << " not found in list.";
}