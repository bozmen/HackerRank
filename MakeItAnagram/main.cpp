#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main() {
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	int count = 0;
	map<char, int> M1, M2;
	for (int i = 0; i < s1.length(); i++) {
		M1[s1[i]]++;
		count++;
	}
	for (int i = 0; i < s2.length(); i++) {
		if (M1[s2[i]] > 0) {
			M1[s2[i]]--;
			count--;
		}
		else
			count++;
	}
	cout << count;
	return 0;
}
