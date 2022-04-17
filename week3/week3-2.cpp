#include <iostream>
using namespace std;

class Stack {

private:
	int size=0;
	char arr[100] = { '0', };

public:
	Stack() {
		size = 0;
	}

	void push(int a) {
		arr[size] = a;
		size++;
	}
	
	void pop(char a) {
		if (size == 0) {
			return;
		}
		if (arr[size - 1] == '*') {
			cout << arr[size-1];
			size--;
			pop(a);
		}
		else {
			if (a == '*') {
				return;
			}
			cout << arr[size-1];
			size--;
		}
	}
};

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string S;
		cin >> S;

		Stack St;
		int j;
		for (j = 0; j < S.size(); j++) {
			if (0 <= S[j] - '0' && S[j] - '0' <= 9) {
				cout << S[j]-'0';
			}
			else {
				St.pop(S[j]);
				St.push(S[j]);
			}
		}
		St.pop(S[j]);
		cout << "\n";
	}
}
