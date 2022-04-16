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
	friend class DoubleLinkedList;
};

class DoubleLinkedList {
private:
	Node* head;
	Node* tail;
	int size;

public:
	DoubleLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void Print() {
		if (size == 0) {
			cout << "empty";
		}
		else {
			Node* curNode = head;
			while (curNode != nullptr) {
				cout << curNode->data<<' ';
				curNode = curNode->next;
			}
		}
	}

	void Append(int x) {
		Node* appendNode = new Node;
		appendNode->data = x;
		if (size == 0) {
			head = appendNode;
			tail = appendNode;
		}
		else {
			tail->next = appendNode;
			appendNode->prev = tail;
			tail = appendNode;
		}
		size++;
		Print();
	}

	int Delete(int index) {
		if (size == 0 || index >= size) {
			return -1;
		}
		else {
			Node* deleteNode = head;
			if (index == 0) {
				head = head->next;
				head->prev = nullptr;
			}
			else {
				Node* prevNode = head;
				for (int i = 0; i < index; i++) {
					prevNode = deleteNode;
					deleteNode = deleteNode->next;
				}
				if (deleteNode == tail) {
					tail = prevNode;
					prevNode->next = nullptr;
				}
				else {
					deleteNode->next->prev = prevNode;
					prevNode->next = deleteNode->next;
				}
			}
			size--;
			return deleteNode->data;
		}
	}
	
	void Print_reverse() {
		if (size == 0) {
			cout << "empty";
		}
		else {
			Node* curNode = tail;
			while (curNode != nullptr) {
				cout << curNode->data<<' ';
				curNode = curNode->prev;
			}
		}
	}

	void Max() {
		if (size == 0) {
			cout << "empty";
		}
		else {
			int maxi = 0;
			Node* curNode = head;
			while (curNode != nullptr) {
				if (curNode->data > maxi) {
					maxi = curNode->data;
				}
				curNode = curNode->next;
			}
			cout << maxi;
		}
	}
};

int main() {
	int M;
	cin >> M;

	DoubleLinkedList ll;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (s == "Print") {
			ll.Print();
		}
		else if (s == "Append") {
			int x;
			cin >> x;
			ll.Append(x);
		}
		else if (s == "Delete") {
			int i;
			cin >> i;
			cout<< ll.Delete(i);
		}
		else if (s == "Print_reverse") {
			ll.Print_reverse();
		}
		else if (s == "Max") {
			ll.Max();
		}

		cout << "\n";

	}
}