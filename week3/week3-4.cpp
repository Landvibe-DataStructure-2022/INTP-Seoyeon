#include <iostream>
using namespace std;

class Stack {
private:
	int size;
	int arr[101] = { 0, };

public:
	Stack() {
		size = 0;
	}

	int pop() {
		int num = arr[size - 1];
		size--;
		return num;
	}

	void push(int a) {
		arr[size] = a;
		size++;
	}

	void top() {
		cout << arr[0] << '\n';
	}
};

int main() {
	int N;
	cin >> N;


	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;

		Stack St;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] - '0' >= 0 && S[j] - '0' <= 9) {
				St.push(S[j] - '0');
			}
			else {
				int num2 = St.pop();
				int num1 = St.pop();
				if (S[j] == '*') {
					St.push((num1 * num2));
				}
				else if (S[j] == '+') {
					St.push((num1 + num2));
				}
				else if (S[j] == '-') {
					St.push(num1 - num2);
				}
			}
		}
		cout<<St.pop()<<'\n';
	}

}