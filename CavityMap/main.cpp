#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int index(int x, int y, int n);
bool check(int x, int y, vector<string> V);

int main() {
	int n;
	cin >> n;
	vector<string> grid(n);
	for (int grid_i = 0; grid_i < n; grid_i++) {
		cin >> grid[grid_i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != 0 && j != 0 && i != n-1 && j != n-1) {
				bool isCavity = check(i, j, grid);
				if (isCavity) {
					cout << "X";
				}
				else {
					cout << grid[i][j];
				}
			}
			else {
				cout << grid[i][j];
			}
		}
		cout << "\n";
	}
	return 0;
}

bool check(int x, int y, vector<string> V) {
	int size = V.size();
	int elem = V[x][y] - '0';
	int n = V[x - 1][y] - '0';
	int s = V[x + 1][y] - '0';
	int e = V[x][y + 1] - '0';
	int w = V[x][y - 1] - '0';
	return elem > n && elem > s && elem > e && elem > w;
}