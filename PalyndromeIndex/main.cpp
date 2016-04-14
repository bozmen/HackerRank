#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		int start = 0;
		int end = s.length() - 1;
		int index = -1;
		while (start < end) {
			if (s[start] == s[end]) {
				start++;
				end--;
				continue;
			}
			else {
				char aStart = s[start + 1];
				char bEnd = s[end - 1];
				if (aStart == s[end]) {
					index = start;
					break;
				}
				else {
					index = end;
					break;
				}
			}
		}
		cout << index << "\n";
	}
	return 0;
}
