#include <iostream>
using namespace std;

class Queue {
private:
	int size;
	int arr[105] = { 0 ,};

public:
	Queue() {
		size = 0;
	}
	
	int dequeue() {
		int num = arr[0];
		for (int i = 0; i < size; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
		return num;
	}

	void enqueue(int v) {
		arr[size] = v;
		size++;
	}



};

int main() {
	int T, R;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> R;
		Queue q1;
		Queue q2;
		for (int j = 0; j < R; j++) {
			int a;
			cin >> a;
			q1.enqueue(a);
		}
		for (int j = 0; j < R; j++) {
			int a;
			cin >> a;
			q2.enqueue(a);
		}

		int bonus1 = 0;
		int bonus2 = 0;
		int win1 = 0;
		int win2 = 0;
		for (int j = 0; j < R; j++) {
			int num1 = q1.dequeue() + bonus1;
			int num2 = q2.dequeue() + bonus2;

			if (num1 > num2) {
				bonus1 = 0;
				bonus2 = num1 - num2;
				win1++;
				cout << "Round" << j + 1 << " P1 " << bonus2<<'\n';
			}
			else if (num1 < num2) {
				bonus2 = 0;
				bonus1 = num2 - num1;
				win2++;
				cout << "Round" << j + 1 << " P2 " << bonus1 << '\n';
			}
			else {
				bonus1 = 0;
				bonus2 = 0;
				cout << "Round" << j + 1 << " Draw\n";
			}

		}
		if (win1 > win2) {
			cout << "Winner P1\n";
		}
		else if (win1 < win2) {
			cout << "Winner P2\n";
		}
		else {
			cout << "Draw\n";
		}
	}
}