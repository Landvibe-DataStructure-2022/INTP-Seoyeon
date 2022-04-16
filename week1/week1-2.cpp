#include <iostream>
using namespace std;

int N;

int mainarr[1001];

void shift(int d) {
	int arr[2001] = { 0, };
	for (int i = 0; i < N-d; i++) {
		arr[i + d] = mainarr[i];
	}

	for (int i = 0; i < d; i++) {
		arr[i] = mainarr[N - d + i];
	}

	for (int i = 0; i < N; i++) {
		mainarr[i] = arr[i];
	}
}

void reverse(int x, int y) {
	int arr1[1001];
	int k = 0;
	for (int i = y; i >= x; i--) {
		arr1[k] = mainarr[i];
		k++;
	}

	int a = 0;
	for (int j = x; j <= y; j++) {
		mainarr[j] = arr1[a];
		a++;
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		cout << mainarr[i] << ' ';
	}
	cout << "\n";
}

int main() {
	int T;
	cin >> T >> N;
	for (int i = 0; i < N; i++) {
		cin >> mainarr[i];
	}

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		if (s == "shift") {
			int d;
			cin >> d;
			shift(d);
		}
		else if (s == "reverse") {
			int a, b;
			cin >> a >> b;
			reverse(a, b);
		}
		else if (s == "print") {
			print();
		}
	}
}
