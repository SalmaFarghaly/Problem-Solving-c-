// https://codeforces.com/contest/682/problem/A
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<=(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

#define MP					make_pair

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	ll x[5], y[5];
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	// based on idea that (x+y)mod 5 = (x mod 5 + y mod 5) mod 5
	// x mod 5 = 0 & y mod 5 = 0
	// x mod 5 = 2 & y mod 5 = 3 and visa versa
	// x mod 5 = 1 & y mod 5 = 4 and visa versa
	lpi(i, 1, n) {
		x[i % 5]++;
	}
	lpi(i, 1, m) {
		y[i % 5]++;
	}
	cout << (x[0]*y[0]+x[1]*y[4]+x[2]*y[3]+x[3]*y[2]+x[4]*y[1]);
	return 0;
}
