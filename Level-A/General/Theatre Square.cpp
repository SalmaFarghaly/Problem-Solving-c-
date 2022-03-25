// https://codeforces.com/contest/1/problem/A

#include<iostream>
using namespace std;
 
typedef long long ll;
 
int main() {
	int n, m, a;
	cin >> n >> m >> a;
	ll x = n / a;
	ll y = m / a;
	if (n % a) {
		x++;
	}
	if (m % a) {
		y++;
	}
	cout << x * y;
	return 0;
}
