#include <iostream>
#include "18.3searchSortAlgorithems.h"

using namespace std;

void printlist(int nums[], int length ) {
    for (int i = 0; i < length; i++) 
        cout << nums[i] << " ";
    cout << endl;
        
}

void Test18_5(){
    int nums[] = { 2, 56, 34, 25, 73, 46, 89, 10, 5, 16 };

    int len = sizeof(nums) / sizeof(nums[0]);

    printlist(nums, len);
    modifiedBubbleSort(nums, len);
    printlist(nums, len);


}