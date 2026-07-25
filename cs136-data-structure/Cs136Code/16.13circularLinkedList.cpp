#include <iostream>
#include "16.13circularLinkedList.h"

using namespace std;

//Overloading the stream insertion operator
template <class Type>
void  circularLinkedList<Type>::print() const
{
	nodeType<Type>* current; //pointer to traverse the list

	current = first->link;

	while (current != first) //while more data to print
	{
		cout << current->info << " ";
		current = current->link;
	}

	cout << first->info << " ";
}

template <class Type>
circularLinkedList<Type>::~circularLinkedList() // destructor
{
	destroyList();
}//end destructor


template <class Type>
void circularLinkedList<Type>::copyList
(const circularLinkedList<Type>& otherList)
{
	nodeType<Type>* newNode;
	nodeType<Type>* current;
	nodeType<Type>* tempFirst;

	if (first != nullptr)
		destroyList();

	if (otherList.first == nullptr)
	{
		first = nullptr;
		count = 0;
	}
	else
	{
		current = otherList.first->link;  //current points to the 
		//list to be copied
		count = otherList.count;

		//copy the first node
		tempFirst = new nodeType<Type>;  //create the node

		tempFirst->info = current->info; //copy the info
		last = tempFirst;    		     //make last point to the 
		//first node
		current = current->link;     //make current point to the 
		//next node

//copy the remaining list
		while (current != otherList.first)
		{
			newNode = new nodeType<Type>;  //create a node
			newNode->info = current->info;
			last->link = newNode;
			last = newNode;

			current = current->link;

		}//end while

		if (tempFirst == last)
		{
			first = tempFirst;
			first->link = first;
		}
		else
		{
			newNode = new nodeType<Type>;  //create a node
			newNode->info = current->info;
			last->link = newNode;
			first = newNode;
			first->link = tempFirst;
		}

	}//end else
}//end copyList

	//copy constructor
template<class Type>
circularLinkedList<Type>::circularLinkedList
(const circularLinkedList<Type>& otherList)
{
	first = nullptr;

	copyList(otherList);

}//end copy constructor

template <class Type>
bool circularLinkedList<Type>::isEmptyList()
{
	return (first == nullptr);
}

template <class Type>
circularLinkedList<Type>::circularLinkedList() // default constructor
{
	first = nullptr;
	count = 0;
}

template <class Type>
void circularLinkedList<Type>::destroyList()
{
	nodeType<Type>* temp;
	nodeType<Type>* current = nullptr;

	if (first != nullptr)
	{
		current = first->link;
		first->link = nullptr;
	}

	while (current != nullptr)
	{
		temp = current;
		current = current->link;
		delete temp;
	}

	first = nullptr;	//initialize last to nullptr; first has already
	//been set to nullptr by the while loop
	count = 0;
}


template <class Type>
void circularLinkedList<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

template <class Type>
int circularLinkedList<Type>::length()
{
	return count;
}  // end length

template <class Type>
Type circularLinkedList<Type>::front()
{
	assert(first != nullptr);
	return first->link->info; //return the info of the first node	
}//end front


template <class Type>
Type circularLinkedList<Type>::back()
{
	assert(first != nullptr);
	return first->info; //return the info of the first node	
}//end back

template <class Type>
bool circularLinkedList<Type>::search(const Type& searchItem)
{
	nodeType<Type>* current; //pointer to traverse the list
	bool found = false;;

	if (first != nullptr)
	{
		current = first->link;

		while (current != first && !found)
			if (current->info >= searchItem)
				found = true;
			else
				current = current->link;

		found = (current->info == searchItem);
	}

	return found;
}//end search

template <class Type>
void circularLinkedList<Type>::insertNode(const Type& newitem)
{
	nodeType<Type>* current; //pointer to traverse the list
	nodeType<Type>* trailCurrent; //pointer just before current
	nodeType<Type>* newNode;  //pointer to create a node

	bool  found;

	newNode = new nodeType<Type>; //create the node

	newNode->info = newitem;   //store newitem in the node
	newNode->link = nullptr;      //set the link field of the node
	//to nullptr

	if (first == nullptr)  //Case 1	
	{
		first = newNode;
		first->link = newNode;
		count++;
	}
	else
	{
		if (newitem >= first->info)
		{
			newNode->link = first->link;
			first->link = newNode;
			first = newNode;
		}
		else
		{
			trailCurrent = first;
			current = first->link;
			found = false;

			while (current != first && !found)
				if (current->info >= newitem)
					found = true;
				else
				{
					trailCurrent = current;
					current = current->link;
				}

			trailCurrent->link = newNode;
			newNode->link = current;
		}

		count++;
	}//end else
}//end insertNode

template <class Type>
void circularLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type>* current; //pointer to traverse the list
	nodeType<Type>* trailCurrent; //pointer just before current
	bool found;

	if (first == nullptr)    //Case 1; list is empty. 
		cerr << "Can not delete from an empty list." << endl;
	else
	{
		found = false;
		trailCurrent = first;
		current = first->link;

		while (current != first && !found)
			if (current->info >= deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}

		if (current == first)
		{
			if (first->info == deleteItem)
			{
				if (first == first->link)
					first = nullptr;
				else
				{
					trailCurrent->link = current->link;
					first = trailCurrent;
				}
				delete current;

				count--;
			}
			else
				cout << "The item to be deleted is not in the list" << endl;
		}
		else
			if (current->info == deleteItem)
			{
				trailCurrent->link = current->link;
				count--;
				delete current;
			}
			else
				cout << "Item to be deleted is not in the list." << endl;
	} //end else
} //end deleteNode




	//overload the assignment operator
template <class Type>
const circularLinkedList<Type>& circularLinkedList<Type>::operator=
(const circularLinkedList<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy
	{
		copyList(otherList);
	}//end else

	return *this;
}


void Test16_13() {
	circularLinkedList<int> myList;
	int num, searchNum, deleteNum;

	cout << " Enter number ending with -999: ";
	cin >> num;

	while (num != -999) {
		myList.insertNode(num);
		cin >> num;
	}
	cout << endl;

	cout << "List 1: ";
	myList.print();
	cout << endl;

	cout << "Length List 1: " << myList.length();

	cout << "\nEnter the number to be searched: ";
	cin >> searchNum;
	cout << endl;

	myList.search(searchNum) ? cout << searchNum << " found in the list\n" : cout << searchNum << " not found in the list\n";

	cout << "\nEnter the number to be deleted: ";
	cin >> deleteNum;
	cout << endl;

	myList.deleteNode(deleteNum);

	cout << "After deleting the node, List 1: ";
	myList.print();
	cout << "\nLength List 1: " << myList.length();
}
