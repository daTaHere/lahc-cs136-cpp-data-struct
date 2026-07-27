#include <iostream>
#include "17.3myStack.h"

void Test17_3() {
	stackType<int> stack1(5);

	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	stack1.push(40);
	stack1.push(50);

	stackType<int> stack2 = stack1;

	cout << "stack1: ";
	stack1.printStack();

	cout << "\nstack2: ";
	stack2.printStack();

	stack1.reverseStack(stack2);

	cout << "\nstack2: ";
	stack2.printStack();
}