#include "stdafx.h"
#include <iostream>

using namespace std;

class Queue {

	//The node of the stack
	struct Node {
		int data;
		Node *next;
	};

	// public members
public:

	// constructor
	Queue() {
		head = NULL;
		tail = NULL;
	}

	// destructor
	~Queue() {
		Node *next = head;

		while (next) {
			Node *deleteMe = next;
			next = next->next;
			delete deleteMe; //please
		}
	}

	//Returns the value of the first item and deletes it
	int deQueue() {
		if (isEmpty()) // There might be an exeption I guess
			return 0;

		Node *newNode = head;
		int ret = newNode->data;

		head = head->next;
		delete newNode;
		return ret;
	}

	// adds the element to the end of the list
	bool inQueue(int data) {
		Node * newNode = new Node();
		newNode->data = data;
		newNode->next = NULL;

		if (tail == NULL) {
			head = newNode;
			tail = head;
		}

		tail->next = newNode;

		tail = tail->next;

		return true;
	}

	//Returns true if the collection is empty
	bool isEmpty() {
		return head == NULL;
	}

	// private members
private:
	Node * head;
	Node * tail;
};		
int main()
{
	Queue * ll = new Queue();

	ll->inQueue(1);
	ll->inQueue(2);
	ll->inQueue(3);

	cout << ll->deQueue() << endl;
	cout << ll->deQueue() << endl;
	cout << ll->deQueue() << endl;
	cout << ll->deQueue() << endl;
	cout << ll->deQueue() << endl;
	cout << ll->deQueue() << endl;

	system("pause");
	return 0;
}


