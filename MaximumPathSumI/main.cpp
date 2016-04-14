#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxPath(int index, int maxLevel, int level, vector<int> V);

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<int> V(N*(N + 1) / 2, 0);
		for (int j = 0; j < V.size(); j++) {
			int e;
			cin >> e;
			V[j] = e;
		}
		cout << maxPath(0, N - 1, 0, V) << "\n";
	}
	return 0;
}

int maxPath(int index, int maxLevel, int level, vector<int> V) {
	int startsAt = (level*(level + 1)) / 2;
	if (level == maxLevel) {
		return V[startsAt + index];
	}
	long long int left = maxPath(index, maxLevel, level + 1, V);
	long long int right = maxPath(index + 1, maxLevel, level + 1, V);
	long long int max = left >= right ? left : right;
	return V[startsAt + index] + max;
}
