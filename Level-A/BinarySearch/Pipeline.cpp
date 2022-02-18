//https://codeforces.com/contest/287/problem/B

#include<iostream>
using namespace std;

typedef long long ll;

ll sum(ll n) {
	return n * (n + 1) / 2;
}

ll sum(ll s, ll e) {
	return sum(e) - sum(s - 1);
}

ll BS(ll k, ll n) {
	ll st = 1;
	ll ed = k;
	while (st < ed) {
		ll md = (st + ed) / 2;
		ll s = sum(md, k);
		if (n == s)
			return k - md + 1;
		if (s > n)
			st = md + 1;
		else
			ed = md;
	}
	return k - st + 2;
}

int main() {
	ll n, k;
	cin >> n >> k;
	if (n == 1)
		cout << "0\n";
	else if (n <= k)
		cout << "1\n";
	else if (n - 1 > sum(k - 1))
		cout << "-1\n";
	else {
		cout<<BS(--k, --n);
	}

	return 0;
}
