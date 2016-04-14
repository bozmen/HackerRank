#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	long long int p, q;
	cin >> p;
	cin >> q;
	int count = 0;
	for (long long int i = p; i <= q; i++) {
		long long int a = i*i;
		string stra = to_string(a);
		string part1 = stra.substr(0, stra.length() / 2);
		string part2 = stra.substr(stra.length() / 2, stra.length() - part1.length());
		if (part1 == "") {
			part1 = "0";
		}
		int ipart1 = std::stoi(part1);
		int ipart2 = std::stoi(part2);
		if (ipart1 + ipart2 == i) {
			cout << i << " ";
			count++;
		}
	}
	if (count == 0) {
		cout << "INVALID RANGE";
	}
	return 0;
}
