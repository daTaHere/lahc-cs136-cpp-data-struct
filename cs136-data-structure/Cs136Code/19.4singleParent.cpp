#include <iostream>
#include "19.1binarySearchTree.h"

void Test19_4() {
	bSearchTreeType<int> bt;

	int nums;
	cout << "Enter intergers and end with -999: ";
	cin >> nums;

	while (nums != -999) {
		bt.insert(nums);
		cin >> nums;
	}

	cout << "preorder: ";
	bt.preorderTraversal();
	cout << endl;



	cout << "Number of single parent nodes: ";
	cout << bt.singleParent();
	cout << endl;
}