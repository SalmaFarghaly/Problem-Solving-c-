// https://codeforces.com/contest/227/problem/B

#include<iostream>
using namespace std;
#include<map>

typedef map<int, int> mii;

int n, m;
long long app1, app2;

int main() {
	cin >> n;
	mii mp;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		mp[num] = i + 1;
	}
	cin >> m;
	while (m--) {
		int q;
		cin >> q;
		if (mp.count(q)) {
			app1 += mp[q];
			app2 += n - mp[q] + 1;
		}
		else {
			app1 += n;
			app2 += n;
		}
	}
	cout << app1 << " " << app2;
	return 0;
}
