#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	vector<int> sum(50, 0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 50; j++) {
			sum[j] += s[j] - '0';
		}
	}
	string result = "";
	for (int i = 49; i >= 0; i--) {
		if (i != 0) {
			string digit = to_string(sum[i] % 10);
			int carry = sum[i] / 10;
			result.insert(0, digit);
			sum[i - 1] += carry;
		}
		else {
			result.insert(0, to_string(sum[i]));
		}
	}
	cout << result.substr(0, 10);
	return 0;
}
