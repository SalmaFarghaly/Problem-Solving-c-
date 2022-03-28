// https://codeforces.com/contest/225/problem/A

#include<iostream>
using namespace std;

int main() {
	int n,top, down, r, l, rr, ll;
	cin >> n >> top >> r >> l;
	while (--n) {
		cin >> r >> l;
		down = 7 - top,rr = 7 - r,ll = 7 - l;
		if (ll == down || rr == down || l == down || r == down) {
			cout << "NO";
			return 0;
		}
		top = 21 - down - ll - rr - l - r;
	}
	cout << "YES";
	return 0;
}
