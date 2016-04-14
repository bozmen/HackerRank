#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int d(int n);

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	cin >> T;
	vector<bool> amicables(100000, NULL);
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		long long int sum = 0;
		for (int j = 1; j < N; j++) {
			if (amicables[j - 1] == true) {
				sum += j;
			}
			else if (amicables[j - 1] == false) {
				continue;
			}
			else {
				long long int dj = d(j);
				long long int ddj = d(dj);
				if (ddj == j && dj != j) {
					amicables[j - 1] = true;
					amicables[dj - 1] = true;
					if (ddj < N)
						sum += j;
				}
				else {
					amicables[j - 1] = false;
				}

			}
		}
		amicables.empty();
		cout << sum << "\n";
	}
	return 0;
}

long long int d(int n) {
	long long int sum = 0;
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum;
}
