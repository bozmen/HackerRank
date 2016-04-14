#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main() {
	string S;
	cin >> S;
	map<char, int> M;
	for (int i = 0; i < S.length(); i++) {
		M[S[i]] += 1;
	}
	for (auto iterator = M.begin(); iterator != M.end(); iterator++) {
		iterator->second = iterator->second / 2;
	}
	string result = "";
	auto iterator = M.begin();
	int length = M.size();
	int index = S.length() - 1;
	for (int i = 0; i < length; i++) {
		if(iterator->second == 0){
			iterator++;
		}
		char c = iterator->first;
		bool found = false;
		while (S[index] != c) {

		}
	}
	return 0;
}
