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
		if (N % 2 == 1) {
			cout << -1 << "\n";
			break;
		}
		N = N / 2;
		bool found = false;
		float m;
		float n;
		long long int max = -1;
		for (m = N*N; m > 0; m--) {
			float msqr = sqrt(m);
			n = (N / msqr) - msqr;
			if (n > 0 && msqr != n) {
				long long int res = (msqr*msqr - n*n)*(2 * msqr*n)*(msqr*msqr + n*n);
				if (res > max) {
					max = res;
				}
				found = true;
			}
		}
		cout << max << "\n";

	}
	return 0;
}
