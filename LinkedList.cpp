#include "stdafx.h"
// linkedList.cpp - Demo program to illustrate linked lists,
//                  using public data members.
#include <iostream>
using namespace std;

//-----------------------------------------------------------
class Node {
public:
	int data;        // The data being stored at the node
	Node *pNext;     // Pointer to the next node
};


//------------------------------------------------------------
// Consider: Does this function destroy the head node pointer?
void displayList(Node *pHead)
{
	cout << "List is: ";
	while (pHead != NULL) {
		cout << pHead->data << " ";
		pHead = pHead->pNext;
	}
	cout << endl;
}


//--------------------------------------------------------------
// Consider: For input of 1 3 5 -1, what is the output?
int main()
{
	Node *pHead = NULL;  // head of linked list 

	cout << "Enter as many integers > 0 as you would like " << endl
		<< "  followed by the value -1. " << endl
		<< endl
		<< "The numbers are: ";

	int number = 0;      // Used to store numbers read in 
	Node *pTemp;         // used in new node creation
	while (number != -1) {
		cin >> number;
		if (number != -1) {
			pTemp = new Node;
			// Insert at head of list 
			pTemp->data = number;
			pTemp->pNext = pHead;
			pHead = pTemp;
		}
	}

	displayList(pHead);

	return 0;         // return value to keep C++ happy
}