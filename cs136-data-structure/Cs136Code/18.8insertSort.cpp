#include <iostream>
#include "18.3searchSortAlgorithems.h"

using namespace std;

void Test18_8() {
	const int size = 10;
	int* userNums = new int[size];

	for (int i = 0; i < 10; i++) {
		cout << "Enter interger " << i+1 << ": ";
		cin >> userNums[i];
		cout << endl;
	}
	printList(userNums, size);

	insertionSort(userNums, size);

	printList(userNums, size);
}