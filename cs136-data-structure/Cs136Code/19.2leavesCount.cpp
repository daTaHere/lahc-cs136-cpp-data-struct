#include <iostream>
#include "19.1binarySearchTree.h"

using namespace std;

void Test19_2() {

	bSearchTreeType<int> bt;

	int nums, deleteNum;
	cout << "Enter intergers and end with -999: ";
	cin >> nums;

	while (nums != -999) {
		bt.insert(nums);
		cin >> nums;
	}

	cout << "Number of leaves: " << bt.treeLeavesCount() << endl;

	cout << "inorder: ";
	bt.inorderTraversal();
	cout << endl;

	cout << "\nEnter number to be deleted: ";
	cin >> deleteNum;
	bt.deleteNode(deleteNum);

	cout << "inorder: ";
	bt.inorderTraversal();
	cout << endl;

	cout << "\nNumber of leaves: " << bt.treeLeavesCount() << endl;
}