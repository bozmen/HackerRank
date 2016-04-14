#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int T;
	cin >> T;
	vector<int> primes;
	primes.push_back(2);
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		if (N <= primes.size()) {
			cout << primes[N - 1] << "\n";
			continue;
		}
		else {
			for (int j = primes.back() + 1; N > primes.size(); j++) {
				bool divides = false;
				for (int k = 0; k < primes.size(); k++) {
					if (j % primes[k] == 0) {
						divides = true;
						break;
					}
				}
				if (!divides) {
					primes.push_back(j);
				}
			}
			cout << primes[N - 1] << "\n";
		}
	}
	return 0;
}
