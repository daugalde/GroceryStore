#include "Object.h"
#include "Node.h"

using namespace std;

class List {

private:
	PointerNode head;
	//PointerNode current;

public:
	List() { head = NULL; /*current = NULL;*/ }
	~List();

	void unshift(int v); // Insert at Beginning
	void push(Object* obj); // Insert at End
	void splice(int v, int pos); // Insert at Index Position
	bool IsEmpty() { return head == NULL; }
	void display(string type);
	void next();
	void first();
	void last();
	void pop();
	void shift();
	void removeAtIndex(int pos);
	void sum(int num);
	int Length();
};
