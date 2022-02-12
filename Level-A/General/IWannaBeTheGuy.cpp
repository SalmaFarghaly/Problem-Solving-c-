//http://codeforces.com/contest/469/problem/A

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main() {
	int n, p, q;
	cin >> n;
	vector<int>vec(n, 0);
	cin >> p;
	int t;
	while (p--) {
		cin >> t;
		vec[t - 1] = 1;
	}
	cin >> q;
	while (q--) {
		cin >> t;
		vec[t - 1] = 1;
	}
	if (all_of(vec.begin(), vec.end(), [](bool v) {return v;}))
		cout << "I become the guy.";
	else
		cout << "Oh, my keyboard!";
	return 0;
}
