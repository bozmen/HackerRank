#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int, vector<int>&);

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<int> V(N, -1);

		for (int j = 0; j < N; j++) {
			int e;
			cin >> e;
			V[j] = e;
		}
		vector<int> sortedV(V);
		std::sort(sortedV.begin(), sortedV.begin() + N);
		int index = 0;
		while (index < N - 2) {
			if (V[index] == sortedV[index]) {
				index++;
				continue;
			}
			else {
				int index2 = 0;
				for (int j = index + 1; j < N; j++) {
					if (sortedV[index] == V[j]) {
						index2 = j;
						break;
					}
				}
				for (int j = 0; j < index2 - index; j++) {
					if (index2 == N - 1) {
						rotate(index2 - 2 - j, V);
						index2 -= 1;
					}
					else {
						rotate(index2 - 1 - j, V);
						index2 -= 1;
					}
				}
				continue;
			}
		}
		if (V[N - 2] < V[N - 1]) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}

void rotate(int a, vector<int>& V) {
	int b = a + 1;
	int c = a + 2;
	int temp = V[a];
	V[a] = V[b];
	V[b] = V[c];
	V[c] = temp;
}
