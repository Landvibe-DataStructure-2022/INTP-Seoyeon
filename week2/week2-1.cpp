#include <iostream>
using namespace std;

class Node {
private:
	Node* next;
	int data;

public:
	Node() {
		next = nullptr;
		data = 0;
	}

	friend class SingleLinkedList;
};

class SingleLinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	SingleLinkedList() {
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
				cout << printNode->data << ' ';
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
			tail = appendNode;
		}

		size++;
		Print();
	}

	int Delete(int index) {
		if (index >= size) {
			return -1;
		}
		Node* deleteNode = head;
		if (index == 0) {
			head = deleteNode->next;
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
				prevNode->next = deleteNode->next;

			}
		}
		size--;
		return deleteNode->data;
	}

	void Insert(int index, int x) {
		if (index > size) {
			cout << "Index Error";
		}
		else {
			Node* insertNode = new Node;
			insertNode->data = x;
			if (index == 0) {
				insertNode->next = head;
				head = insertNode;
				Print();
				size++;
			}
			else if (index == size) {
				Append(x);
			}
			else {
				Node* prevNode = head;
				for (int i = 0; i < index - 1; i++) {
					prevNode = prevNode->next;
				}
				insertNode->next = prevNode->next;
				prevNode->next = insertNode;
				Print();
				size++;
			}
		}
	}
		

	void Min() {
		if (size == 0) {
			cout << "empty";
		}
		else {
			int mini = 10001;
			Node* curNode = head;
			while (curNode != nullptr) {
				if (curNode->data < mini) {
					mini = curNode->data;
				}
				curNode = curNode->next;
			}
			cout << mini;
		}

	}
};

int main() {
	int M;
	cin >> M;

	SingleLinkedList ll;
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
		else if (s == "Insert") {
			int index, x;
			cin >> index >> x;
			ll.Insert(index, x);
		}
		else if (s == "Min") {
			ll.Min();
		}
		cout << "\n";
	}
}