#include <iostream>
using namespace std;

int arr[1001];
int N;

void add(int index, int data) {
	for (int i = N - 1; i > index - 1; i--) {
		arr[i + 1] = arr[i];
	}
	arr[index] = data;
}

void remove(int index) {
	for (int i = index; i < N - 1; i++) {
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
	cout << "\n";
}

void find(int data) {
	int num = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i] == data) {
			num++;
		}
	}
	cout << num << '\n';
}

int main() {
	int T;
	cin >> T >> N;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;

		if (s == "add") {
			int a, b;
			cin >> a >> b;
			add(a, b);
		}
		else if (s == "remove") {
			int a;
			cin >> a;
			remove(a);
		}
		else if (s == "set") {
			int a, b;
			cin >> a >> b;
			set(a, b);
		}
		else if (s == "print") {
			print();
		}

		else if (s == "find") {
			int a;
			cin >> a;
			find(a);
		}

	}

}
