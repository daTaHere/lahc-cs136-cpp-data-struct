#include <iostream>
#include "19.1binarySearchTree.h"

using namespace std;

void Test19_1() {

	bSearchTreeType<int> bt;

	int nums, deleteNum;
	cout << "Enter intergers and end with -999: ";
	cin >> nums;

	while (nums != -999) {
		bt.insert(nums);
		cin >> nums;
	}

	cout << "Number of Nodes: " << bt.treeNodeCount() << endl;

	cout << "\nEnter number to be deleted: ";
	cin >> deleteNum;
	bt.deleteNode(deleteNum);

	cout << "\nNumber of Nodes: " << bt.treeNodeCount() << endl;
}