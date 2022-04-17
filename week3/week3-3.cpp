#include <iostream>
using namespace std;

class Node {
private:
	Node* next;
	Node* prev;
	int data;

public:
	Node() {
		next = nullptr;
		prev = nullptr;
		data = 0;
	}

	friend class LinkedList;
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int size;

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	int getSize() {
		return size;
	}

	void empty() {
		if (size == 0) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}

	void top() {
		if (size == 0) {
			cout << "-1\n";
		}
		else {
			cout << tail->data << '\n';
		}
	}

	void push(int x) {
		Node* pushNode = new Node;
		pushNode->data = x;

		if (size == 0) {
			head = pushNode;
			tail = pushNode;
		}
		else {
			tail->next = pushNode;
			pushNode->prev = tail;
			tail = pushNode;
		}
		size++;
	}

	void pop() {
		if (size == 0) {
			cout << "-1\n";
		}
		else {
			cout << tail->data << '\n';
			tail = tail->prev;

			size--;
		}
	}
};

int main() {
	LinkedList ll;

	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;

		if (s == "size") {
			cout << ll.getSize() << '\n';
		}
		else if (s == "empty") {
			ll.empty();
		}
		else if (s == "top") {
			ll.top();
		}
		else if (s == "push") {
			int x;
			cin >> x;
			ll.push(x);
		}
		else if (s == "pop") {
			ll.pop();
		}
	}
	
}