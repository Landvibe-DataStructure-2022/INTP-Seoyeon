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
	friend class Queue;
};

class Queue {
private:
	Node* head;
	Node* tail;
	int size;

public:
	Queue() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	int getSize() {
		return size;
	}

	void isEmpty() {
		if (size == 0) {
			cout << "True\n";
		}
		else {
			cout << "False\n";
		}
	}

	void front() {
		if (size == 0) {
			cout << "Empty\n";
		}
		else {
			cout << head->data << "\n";
		}
	}

	void rear() {
		if (size == 0) {
			cout << "Empty\n";
		}
		else {
			cout << tail->data<<'\n';
		}
	}

	void enqueue(int value) {
		Node* insertNode = new Node;
		insertNode->data = value;
		if (size == 0) {
			head = insertNode;
			tail = insertNode;
		}
		else {
			tail->next = insertNode;
			insertNode->prev = tail;
			tail = insertNode;
		}
		size++;
	}

	void dequeue() {
		if (size == 0) {
			cout << "Empty\n";
		}
		else {
			Node* deleteNode = head;
			if (size == 1) {
				head = nullptr;
				tail = nullptr;
			}
			else {
				head = head->next;
				head->prev = nullptr;
			}

			cout << deleteNode->data << "\n";
			size--;
		}
	}
};

int main() {
	int T;
	cin >> T;

	Queue q;
	while (T--) {
		string s;
		cin >> s;

		if (s == "size") {
			cout << q.getSize() << '\n';
		}
		else if (s == "isEmpty") {
			q.isEmpty();
		}
		else if (s == "front") {
			q.front();
		}
		else if (s == "rear") {
			q.rear();
		}
		else if (s == "enqueue") {
			int value;
			cin >> value;
			q.enqueue(value);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
	}
}