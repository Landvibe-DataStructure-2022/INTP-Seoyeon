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
	int size;
	Node* head;
	Node* tail;

public:
	Queue() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	int dequeue() {
		Node* deleteNode = head;
		if (size == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
			head->prev = nullptr;
		}
		size--;
		return deleteNode->data;
	}

	void enqueue(int a) {
		Node* newNode = new Node;
		newNode->data = a;
		if (size == 0) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		size++;
	}
};

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		Queue q1;
		Queue q2;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			q1.enqueue(a);
		}
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			q2.enqueue(a);
		}
		int bonus1 = 0;
		int bonus2 = 0;
		int win1 = 0;
		int win2 = 0;
		for (int j = 0; j < N; j++) {
			int num1 = bonus1 + q1.dequeue();
			int num2 = bonus2 + q2.dequeue();

			if (num1 > num2) {
				bonus1 = num1 - num2;
				bonus2 = 0;
				win1++;
			}
			else if (num1 < num2) {
				bonus2 = num2-num1;
				bonus1 = 0;
				win2++;
			}
			else {
				bonus1 = 0;
				bonus2 = 0;
			}
			cout << "Round" << j+1 << ' ' << win1 << ":" << win2<<"\n";
			
		}
		if (win1 > win2) {
			cout << "Winner P1\n";
		}
		else if (win1 < win2) {
			cout << "Winner P2\n";
		}
		else {
			cout << "Draw\n";
		}
	}
}