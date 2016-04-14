#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int evenFibonacci(int, map<long long int, long long int>*);

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int a;
		cin >> a;
		a = ((a - 2) / 3) + 1;
		map<long long int, long long int>* iterated = new map<long long int, long long int>();
		long long int sum = 0;
		long long int lastterm = 0;
		for (int j = 0; j < a && lastterm < a; j++) {
			lastterm = evenFibonacci(j + 1, iterated);
			sum += lastterm;
		}
		cout << sum << "\n";
	}
	return 0;
}

int evenFibonacci(int n, map<long long int, long long int>* iterated) {
	if (n == 1)
		return 2;
	else if (n == 2)
		return 8;
	else {
		if ((*iterated)[n] != 0)
			return (*iterated)[n];
		else {
			long long int res = (4 * evenFibonacci(n - 1, iterated)) + (1 * evenFibonacci(n - 2, iterated));
			(*iterated)[n] = res;
			return res;
		}
	}
}

