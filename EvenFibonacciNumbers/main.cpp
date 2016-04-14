#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
			long long int N;
		cin >> N;
		long long int evensum = 0;
		long long int fib1 = 1;
		long long int fib2 = 1;
		while (fib1 < N) {
			if (fib1 % 2 == 0) {
				evensum += fib1;
			}
			long long int temp = fib1;
			fib1 = fib2;
			fib2 = temp + fib2;
		}
		cout << evensum << "\n";
	}
	return 0;
}
