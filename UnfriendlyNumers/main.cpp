#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int unfriendlyNumbers(vector < long long int > a, long long int k) {
	int ans;
	set<long long int> divisors;
	for (int i = 2; i <= k / 2; i++) {
		divisors.insert(i);
	}
	divisors.insert(k);
	for (int i = 0; i < a.size(); i++) {
		if (divisors.size() == 0)
			break;
		for (set<long long int>::iterator it = divisors.begin(); it != divisors.end();) {
			if (a[i] % *it == 0) {
				int a = *it;
				it++;
				divisors.erase(a);
				continue;
			}
			++it;
		}
	}
	ans = divisors.size();
	return ans;
}

/* Tail starts here */
int main() {
	int res;

	int _a_size;
	long long int _k;
	cin >> _a_size >> _k;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<long long int> _a;
	long long int _a_item;
	for (int _a_i = 0; _a_i<_a_size; _a_i++) {
		cin >> _a_item;
		_a.push_back(_a_item);
	}

	res = unfriendlyNumbers(_a, _k);
	cout << res;
	cin >> res;
	return 0;
}
