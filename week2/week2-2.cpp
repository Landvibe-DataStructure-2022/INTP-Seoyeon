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
			Node* printNode = head;
			while (printNode != nullptr) {
				cout << printNode->data<<' ';
				printNode = printNode->next;
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
		if (size == 0 || size <= index) {
			return -1;
		} 

		Node* deleteNode = head;

		if (index == 0) {
			head->next = head;
		}
		else {
			for (int i = 0; i < index; i++) {
				deleteNode = deleteNode->next;
			}

			if (deleteNode == tail) {
				tail=deleteNode->prev;
				tail->next = nullptr;
			}
			else {
				deleteNode->prev->next = deleteNode->next;
				deleteNode->next->prev = deleteNode->prev;
			}
		}
		size--;
		return deleteNode->data;
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

	void Update(int x, int y) {

		bool success = false;
		if (size == 0) {
			cout << "empty";
		}
		else {
			Node* curNode = head;
			while (curNode != nullptr) {
				if (curNode->data == x) {
					curNode->data = y;
					success = true;
				}
				curNode = curNode->next;
			}
			if (!success) {
				cout << "Not found";
			}
			else {
				Print();
			}

		}
	}

};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
			int index;
			cin >> index;
			cout<<ll.Delete(index);
		}
		else if (s == "Print_reverse") {
			ll.Print_reverse();
		}
		else if (s == "Update") {
			int x, y;
			cin >> x >> y;
			ll.Update(x, y);
		}
		cout << "\n";
	}


}