#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int countPath(int n, int m, int N, int M, vector<vector<long long int>>& V);

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	cin >> T;
	vector<vector<long long int>> *V = new vector<vector<long long int>>(501, vector<long long int>(501, 0));
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N;
		cin >> M;
		cout << countPath(0, 0, N, M, *V) << "\n";
	}
	return 0;
}

long long int countPath(int n, int m, int N, int M, vector<vector<long long int>>& V) {
	if (n == N && m == M) {
		return 1;
	}
	else {
		int xOffset = N - n;
		int yOffset = M - m;
		long long int precomputed = V[500 - xOffset][500 - yOffset];
		if (precomputed > 0) {
			return precomputed % 1000000007;
		}
		else {
			long long int right = 0;
			if (m < M) {
				right = countPath(n, m + 1, N, M, V);
			}
			long long int down = 0;
			if (n < N) {
				down = countPath(n + 1, m, N, M, V);
			}
			V[500 - xOffset][500 - yOffset] += (right + down) % 1000000007;
			return (right + down) % 1000000007;
		}
	}
}
