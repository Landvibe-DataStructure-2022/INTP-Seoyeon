#include <iostream>
using namespace std;

int N, T;
class Queue {
private:
	int size;
	int arr[10001] = { 0, };

public:
	Queue() {
		size = 0;
	}

	int GetSize() {
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
			cout << arr[0]<<'\n';
		
		}
	}

	void rear() {
		if (size == 0) {
			cout << "Empty\n";
		}
		else {
			cout << arr[size - 1] << '\n';
		}
	}

	void enqueue(int value) {
		if (size == N) {
			cout << "Full\n";
		}
		else {
			arr[size] = value;
			size++;
		}
	}

	void dequeue() {
		if (size == 0) {
			cout << "Empty\n";
		}
		else {
			int num = arr[0];
			for (int i = 0; i < size; i++) {
				arr[i] = arr[i + 1];
			}
			arr[size - 1] = 0;
			size--;
			cout << num << "\n";
		}
	}
};

int main() {
	cin >> N >> T;
	Queue q;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		if (s == "size") {
			cout << q.GetSize() << "\n";
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
			int v;
			cin >> v;
			q.enqueue(v);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
	}
}