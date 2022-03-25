// https://codeforces.com/contest/483/problem/A

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<climits>
 
using namespace std;
 
typedef long long ll;
typedef map<string, int> mp;
typedef vector<int> vec;
 
#define all(v) ((v).begin()),((v).end())
 
int main() {
	ll l,r;
	cin >> l >> r;
	ll a, b, c;
	if (l % 2) {
		a = l + 1;
	}
	else {
		a = l;
	}
	b = a + 1, c = a + 2;
	if (b > r || c > r || b > LLONG_MAX || c >LLONG_MAX || b < LLONG_MIN || c < LLONG_MIN) {
		cout << -1;
	}
	else {
		cout << a << " " << b << " " << c;
	}
	return 0;
}
