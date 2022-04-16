#include <iostream>
using namespace std;

int mainarr[1001];
int N;

void shift(int d) {
	int arr1[2001] = { 0, };
	int a = 0;
	for (int i = d; i < N; i++) {
		arr1[a] = mainarr[i];
		a++;
	}

	for (int j = 0; j < d; j++) {
		arr1[N - d + j] = mainarr[j];
	}

	for (int k = 0; k < N; k++) {
		mainarr[k] = arr1[k];
	}
}

void reverse(int x, int y) {
	int arr2[1001] = { 0, };
	int a = 0;
	for (int i = y; i >= x; i--) {
		arr2[a] = mainarr[i];
		a++;
	}

	for (int j = x; j <= y; j++) {
		mainarr[j] = arr2[j - x];
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
