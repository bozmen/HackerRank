#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int powerDigitSum(int a, vector<long long int>& V);

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	vector<long long int> *V = new vector<long long int>(10000, 0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << powerDigitSum(N, *V) << "\n";
	}
	return 0;
}

long long int powerDigitSum(int a, vector<long long int>& V) {
	if (a == 1)
		return 2;
	if (V[a - 1] > 0)
		return V[a - 1];
	else {
		if (a % 2 == 0) {
			long long int number = powerDigitSum(a / 2, V)*powerDigitSum(a / 2, V);
			long long int sum = 0;
			while (number != 0) {
				sum += number % 10;
				number /= 10;
			}
			V[a - 1] = sum;
			return sum;
		}
		else {
			long long int number = powerDigitSum(a / 2, V)*powerDigitSum((a / 2) + 1, V);
			long long int sum = 0;
			while (number != 0) {
				sum += number % 10;
				number /= 10;
			}
			V[a - 1] = sum;
			return sum;
		}
	}
}
