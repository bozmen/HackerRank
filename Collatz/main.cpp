#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	vector<long long int> collatzs(5000002, -1);
	vector<long long int> collatzsVal(5000002, -1);
	long long int a = 1;
	collatzs[0] = 1;
	collatzsVal[0] = 1;
	long long int T;
	cin >> T;
	for (long long int i = 0; i < T; i++) {
		long long int N;
		cin >> N;
		if (N < a) {
			cout << collatzs[N - 1] << "\n";
			continue;
		}
		else {
			while (a <= N) {
				long long int max = collatzsVal[collatzs[a - 1] - 1];
				long long int b = a + 1;
				long long int count = 0;
				while (b != 1) {
					if (b <= 5000002 && collatzs[b - 1] >= 0) {
						//cout << count << " " << b - 1 << " 1 \n";
						count += collatzsVal[b - 1] - 1;
						break;
					}
					else if (b % 2 == 1) {
						//cout << count << " " << b - 1 << " 2 \n";
						b = 3 * b + 1;
						count++;
						continue;
					}
					else if (b % 2 == 0) {
						//cout << count << " " << b - 1 << " 3 \n";
						b = b / 2;
						count++;
						continue;
					}
				}
				count++;
				collatzsVal[a] = count;
				if (count >= max) {
					collatzs[a] = a + 1;
				}
				else {
					collatzs[a] = collatzs[a - 1];
				}
				a++;
			}
		}
		cout << collatzs[N - 1] << "\n";
	}
	return 0;
}
