// http://codeforces.com/contest/486/problem/A

#include<iostream>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll ans = (n + 1) / 2;
	cout << (n % 2 == 1 ?  -1 * ans : ans);
	return 0;
}
