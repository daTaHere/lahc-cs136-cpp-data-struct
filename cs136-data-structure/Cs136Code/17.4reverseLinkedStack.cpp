#include <iostream>
#include "17.4linkedStack.h"

using namespace std;

void Test17_4() {
	linkedStackType<int> stack1;

	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	stack1.push(40);
	stack1.push(50);

	linkedStackType<int> stack2 = stack1;

	cout << "stack1: ";
	stack1.printLinkedStack();

	cout << "\nstack2: ";
	stack2.printLinkedStack();

	stack1.reverseStack(stack2);

	cout << "\nstack2: ";
	stack2.printLinkedStack();
}