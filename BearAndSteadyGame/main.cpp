#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	string s;
	cin >> s;
	std::map<char, int> M;
	M['C'] = 0;
	M['T'] = 0;
	M['G'] = 0;
	M['A'] = 0;
	int need = n / 4;
	for (int i = 0; i < n; i++) {
		M[s[i]]++;
	};
	int min = n;
	int end = -1;
	std::map<char, int> PREV;
	PREV['C'] = 0;
	PREV['T'] = 0;
	PREV['G'] = 0;
	PREV['A'] = 0;
	for (int start = 0; end < n && start < n; start++) {
		if (start > 0) {
			PREV[s[start - 1]]--;
		}
		std::map<char, int> CUR;
		bool exit = false;
		bool found = false;
		CUR['A'] = PREV['A'];
		CUR['T'] = PREV['T'];
		CUR['G'] = PREV['G'];
		CUR['C'] = PREV['C'];
		int tempEnd = end;
		while (!(CUR['A'] >= (M['A'] - need)) || !(CUR['C'] >= (M['C'] - need)) || !(CUR['T'] >= (M['T'] - need)) || !(CUR['G'] >= (M['G'] - need))) {
			tempEnd++;
			if (end + 1 >= n) {
				exit = true;
				break;
			}
			if (!(CUR[s[tempEnd] > M['A'] - need])) {
				CUR[s[tempEnd]]++;
				end = tempEnd;
			}
		}
		while (true) {
			if (start == n) {
				break;
			}
			char cur = s[start];
			
			if (CUR[cur] - 1 >= M[cur] - need) {
				start++;
				CUR[cur]--;
				continue;
			}
			else if((CUR['A'] >= (M['A'] - need)) && (CUR['C'] >= (M['C'] - need)) && (CUR['T'] >= (M['T'] - need)) && (CUR['G'] >= (M['G'] - need))){
				found = true;
				break;
			}
			else{
				found = false;
				break;
			}
		}
		if (found && (end - start + 1 < min)) {
			min = end - start + 1;
		}
		PREV['A'] = CUR['A'];
		PREV['T'] = CUR['T'];
		PREV['G'] = CUR['G'];
		PREV['C'] = CUR['C'];
	};
	cout << min;
	return 0;
}
