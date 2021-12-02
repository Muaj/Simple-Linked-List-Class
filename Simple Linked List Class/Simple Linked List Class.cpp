// Simple Linked List Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class LinkedList 
{
protected:
	// Declare a class for the list node
	struct ListNode
	{
		double value;
		ListNode* next;

		ListNode(double value1, ListNode* next1 = nullptr)
		{
			value = value1;
			next  = next1;
		}
	};

	ListNode* head; //link head pointer

public:
	LinkedList() { head = nullptr; } //Constructor
	~LinkedList();				   //Deconstructor

	void add(double num);
	bool isMember(double num);
};


void LinkedList :: add(double num)
{
	if (head == nullptr)
	{
		head = new ListNode(num);
	}
	else
	{
		ListNode* nodePtr = head;
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = new ListNode(num);
	}
}

bool LinkedList:: isMember(double num)
{
	ListNode* ptr = head; //point at head of list
	while (ptr != nullptr) //while list isnt empty
	{
		if (ptr->value == num) //search for num
		{
			return true;
		}
		ptr = ptr->next; //iterate through list

	}
	return false; //if not found return false
}

//Destructor that deletes memory for the list
LinkedList::~LinkedList()
{
	while (head != 0)
	{
		ListNode* p = head;
		head = head->next;
		delete p;
	}
}


int main()
{
	cout << "This program contructs a list of numbers then lets the user to check if there are numbers in the list." << endl;

	//create list
	LinkedList list1;

	//ask user input to the list
	cout << "Enter 5 numbers" << endl;

	for (int i = 0; i < 4; i++)
	{
		double num;
		cin >> num;
		list1.add(num);
	}

	//Test for numbers

	

	
	while ("c")
	{
		cout << "Test to see if a number is in the list" << endl;
		double num;
		cin >> num;
		if (list1.isMember(num))
		{
			cout << "\n" << num << " is in the list." << endl;
		}
		else
		{
			cout << "\n" << num << " isn't in the list." << endl;
		}
		cout << "Test to see if a number is in the list" << endl;
		cout << "Enter 'q' to quit and 'c' to continue" << endl;
		string tester;
		cin >> tester;
		if (tester == "q")
		{
			break;
		}

	}
	return 0;
}

