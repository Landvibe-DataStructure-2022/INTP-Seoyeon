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
			Node* curNode = head;
			while (curNode != nullptr) {
				cout << curNode->data << " ";
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
			tail = appendNode;
		}
		size++;
		Print();
	}

	int Delete(int index) {
		if (size == 0 || index >= size) {
			return -1;
		}
		Node* deleteNode = head;
		if (index == 0) {
			if (size == 1) {
				head = nullptr;
				tail = nullptr;
			}
			else {
				head = head->next;
			}
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
				if (size == 0) {
					head = insertNode;
					tail = insertNode;
				}
				else {
					insertNode->next = head;
					head = insertNode;
				}
				size++;
				Print();
			}
			else if (index == size) {
				Append(x);
			}
			else {
				Node* prevNode = head;
				for (int i = 0; i < index-1; i++) {
					prevNode = prevNode->next;
				}
				insertNode->next = prevNode->next;
				prevNode->next = insertNode;
				Print();
				size++;
			}
		}
	}

	void Sum() {
		int num = 0;
		if (size == 0) {
			cout << 0;
		}
		else {
			Node* curNode = head;
			while (curNode != nullptr) {
				num += curNode->data;
				curNode = curNode->next;
			}
			cout << num;
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
			int a;
			cin >> a;
			ll.Append(a);
		}
		else if (s == "Delete") {
			int index;
			cin >> index;
			cout<<ll.Delete(index);
		}
		else if (s == "Insert") {
			int a, b;
			cin >> a>>b;
			ll.Insert(a, b);
		}
		else if (s == "Sum") {
			ll.Sum();
		}
		cout << "\n";
	}
}