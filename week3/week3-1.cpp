#include <iostream>
using namespace std;

int t, N;

class Stack {
private:
	int size;
	int arr[20] = { 0 , };
public:
	Stack() {
		size = 0;
	}

	int getsize() {
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
			cout << arr[size - 1]<<"\n";
		}
	}

	void push(int x) {
		if (size == t) {
			cout << "FULL\n";
		}
		else {
			arr[size] = x;
			size++;
		}
	}

	void pop() {
		if (size == 0) {
			cout << "-1\n";
		}
		else {
			cout << arr[size - 1]<<"\n";
			arr[size - 1] = 0;
			size--;
		}
	}

};

int main() {
	cin >> t >> N;

	Stack St;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		if (s == "size") {
			cout<<St.getsize()<<'\n';
		}
		else if (s == "empty") {
			St.empty();
		}
		else if (s == "top") {
			St.top();
		}
		else if (s == "push") {
			int x;
			cin >> x;
			St.push(x);
		}
		else if (s == "pop") {
			St.pop();
		}
	}
}