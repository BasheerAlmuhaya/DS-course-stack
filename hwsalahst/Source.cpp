// firstLastList.cpp
// demonstrates list with first and last references
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Node
{
public:
	double Data; // data item
	Node *Next;	 // ptr to next Node in list
	//------------------------------------------------------------
	Node(double d) : Data(d), Next(NULL) {} // constructor
	//------------------------------------------------------------
	void displayNode() // display this Node
	{
		cout << Data << "  ";
	}
	//------------------------------------------------------------
}; // end class Node
////////////////////////////////////////////////////////////////
class Stack
{
	Node *top; // ptr to first Node
public:
	//------------------------------------------------------------
	Stack() : top(NULL) {} // constructor
	//------------------------------------------------------------
	~Stack()				// destructor
	{						//  (deletes all Nodes)
		Node *ptr = top;	// start at beginning
		while (ptr != NULL) // until end of list,
		{
			Node *temp = ptr; // remember current
			ptr = ptr->Next;  // move to next Node
			delete temp;	  // delete old current
		}
	}
	//------------------------------------------------------------
	bool isEmpty() // true if no Nodes
	{
		return top == NULL;
	}
	//------------------------------------------------------------
	void push(double dd) // insert at front of list
	{
		Node *NewNode = new Node(dd); // make new Node
		NewNode->Next = top;		  // newNode --> old first
		top = NewNode;				  // first --> newNode
	}
	//------------------------------------------------------------
	void pop() // remove first Node
	{		   //(assumes non-empty list)
		if (isEmpty())
			return;
		Node *temp = top; // remember first Node
		top = top->Next;  // first --> old next
		delete temp;	  // delete the Node
	} //------------------------------------------------------------
	void displayList()
	{
		if (isEmpty())
		{
			cout << "empty";
			return;
		}
		cout << "List (first-->last): ";
		Node *ptr = top;	// start at beginning
		while (ptr != NULL) // until end of list,
		{
			ptr->displayNode(); // print data
			ptr = ptr->Next;	// move to next Node
		}
		cout << endl;
	} //------------------------------------------------------------
	void dis(Node *p) //display function
	{
		if (p == NULL)
			return;
		p->displayNode();
		dis(p->Next);
	}
}; // end class Stack
////////////////////////////////////////////////////////////////
int main()
{
	Stack theList;	  // make a new list
	theList.push(22); // insert at top
	theList.push(44);
	theList.push(66);
	theList.displayList(); // display the list
	cout << "Deleting first two items" << endl;
	theList.pop(); // remove first two items
	theList.pop();
	theList.displayList(); // display again
	theList.pop();
	theList.pop();
	theList.displayList(); // display again
	system("pause");
	return 0;
} // end main()
