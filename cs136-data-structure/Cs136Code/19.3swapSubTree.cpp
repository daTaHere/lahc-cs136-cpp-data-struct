#include <iostream>
#include "19.1binarySearchTree.h"

void Test19_3() {
	bSearchTreeType<int> bt;

	int nums;
	cout << "Enter intergers and end with -999: ";
	cin >> nums;

	while (nums != -999) {
		bt.insert(nums);
		cin >> nums;
	}

	cout << "Number of leaves: " << bt.treeLeavesCount() << endl;

	cout << "preorder: ";
	bt.preorderTraversal();
	cout << endl;

	cout << "\nSwap: ";
	bt.swapSubtrees();
	cout << endl;

	cout << "preorder: ";
	bt.preorderTraversal();
	cout << endl;
}
