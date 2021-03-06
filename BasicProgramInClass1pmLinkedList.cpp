// BasicProgramInClass1pmLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Linked List program written in class
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node * pNext;
};


//---------------------------------------------------------------------     
void displayList(Node *pHead)
{
	while (pHead != NULL) {
		cout << pHead->data << " ";   // Display the data
		pHead = pHead->pNext;         // Advance to the next node
	}
}


//---------------------------------------------------------------------     
// Return the number of nodes on the list
int count(Node *pHead)
{
	int counter = 0;

	while (pHead != NULL) {
		counter++;
		pHead = pHead->pNext;         // Advance to the next node
	}

	return counter;
}


//---------------------------------------------------------------------     
void prepend(Node *&pHead, int number)
{
	// Store the number on the list
	Node *pTemp = new Node;        // Get a new node
	pTemp->data = number;    // Store the current number in that node
	pTemp->pNext = pHead;    // Make this new node point to the current head of the list
	pHead = pTemp;           // Reset the current head of the list to now point to this new node
}


//----------------------------------------------------------------------
// Return a pointer to the last node on the list, or NULL if it is empty.
Node *findLastNodeOnList(Node *pTemp)
{
	while (pTemp != NULL && pTemp->pNext != NULL) {
		pTemp = pTemp->pNext;
	}

	return pTemp;
}


//----------------------------------------------------------------------
// Create a new node, put the userInput number in it, and APPEND
// it at the END of the list.
void append(Node *&pHead, int userInput)
{
	Node *pTemp = new Node;
	pTemp->data = userInput;
	pTemp->pNext = NULL;

	Node *pEndOfList = findLastNodeOnList(pHead);

	if (pEndOfList == NULL) {
		pHead = pTemp;
	}
	else {
		pEndOfList->pNext = pTemp;
	}
}


//---------------------------------------------------------------------     
void appendList(Node *&pHead, Node *pHeadB)
{
	// see if first list is empty
	if (pHead == NULL) {
		pHead = pHeadB;
	}
	else {
		// first list is not empty
		Node *pEndOfList = findLastNodeOnList(pHead);
		pEndOfList->pNext = pHeadB;
	}
}

//---------------------------------------------------------------------     
int main()
{
	Node *pHead = NULL;
	Node *pTemp;
	int number;

	cout << "Enter numbers for list A, followed by -1: ";
	do {
		cin >> number;
		if (number == -1) {
			break;  // break out of loop
		}

		// prepend( pHead, number);
		append(pHead, number);

	} while (number != -1);

	displayList(pHead);
	cout << endl;

	//cout << "There are " << count( pHead) << " nodes on the list." << endl;

	Node *pHeadB = NULL;
	cout << "Enter numbers for list B, followed by -1: ";
	do {
		cin >> number;
		if (number == -1) {
			break;  // break out of loop
		}

		append(pHeadB, number);

	} while (number != -1);

	displayList(pHeadB);
	cout << endl;

	appendList(pHead, pHeadB);
	displayList(pHead);
	cout << endl;

	return 0;
}