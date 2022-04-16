#include <iostream>
using namespace std;

int arr[1001];
int N;

void add(int index, int data) {
	for (int i = N-1; i > index-1; i--) {
		arr[i + 1] = arr[i];
	}

	arr[index] = data;
}

void remove(int index) {
	for (int i = index; i < N-1; i++) {
		arr[i] = arr[i + 1];
	}

	arr[N - 1] = 0;
}

void set(int index, int data) {
	arr[index] = data;
}

void print() {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	}
}

int find(int data) {
	for (int i = 0; i < N; i++) {
		if (data == arr[i]) {
			return i;
		}
	}
	return -1;
}

int main() {
	int T;
	cin>> T>>N;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		if (s == "add") {
			int x, y;
			cin >> x>> y;
			add(x, y);
		}
		else if (s == "remove") {
			int x;
			cin >> x;
			remove(x);
		}
		else if (s == "set") {
			int x,y;
			cin >> x>>y ;
			set(x, y);
		}
		else if (s == "print") {
			print();
			cout << "\n";
		}
		else if (s == "find") {
			int x;
			cin >> x;
			cout<< find(x);
			cout << "\n";
		}
	}

}
