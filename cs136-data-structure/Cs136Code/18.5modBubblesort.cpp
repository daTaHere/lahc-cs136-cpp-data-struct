#include <iostream>
#include "18.3searchSortAlgorithems.h"

using namespace std;

void Test18_5(){
    int nums[] = { 2, 56, 34, 25, 73, 46, 89, 10, 5, 16 };

    int len = sizeof(nums) / sizeof(nums[0]);

    printList(nums, len);
    modifiedBubbleSort(nums, len);
    printList(nums, len);


}