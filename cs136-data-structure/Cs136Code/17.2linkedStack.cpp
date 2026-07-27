#include <iostream>
#include "17.2linkedStack.h"

void Test17_2() {
	linkedStackType<int> stack1;

	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	stack1.push(40);
	stack1.push(50);

	linkedStackType<int> stack2 = stack1;


	cout << (stack1 == stack2 ? "True" : "False") << endl;

	stack1.pop();

	cout << (stack1 == stack2 ? "True" : "False") << endl;

	stack2.pop();

	cout << (stack1 == stack2 ? "True" : "False") << endl;
}