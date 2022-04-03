// https://codeforces.com/contest/143/problem/A

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
	int r1, r2, c1, c2, d1, d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	int u1 = 0, u2 = 0, l1 = 0, l2 = 0;
	int st = 1;
	bool ok = false;
	while (st <= 9 && st < r1  && !ok) {
		ok = true;
		u1 = st;
		u2 = r1 - u1;
		l2 = c2 - u2;
		l1 = c1 - u1;
		if (l2 <= 0 || l1 <= 0 || u2 <= 0 || d1 != u1 + l2 || d2 != u2 + l1 || u1 == u2 || u1 == l1 || u1 == l2 || u2 == l1 || u2 == l2 || l1 == l2 || l1 >9 ||
			l2 >9 || u1 >9 || u2> 9 || l2 + l1 != r2) {
			u1 = 0, u2 = 0, l1 = 0, l2 = 0;
			st++;
			ok = false;
		}
	}
	if (ok) {
		cout << u1 << " " << u2 << endl << l1 << " " << l2;
	}
	else
		cout << -1;
	return 0;
}
