// https://codeforces.com/contest/469/problem/B

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
#include<list>
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
typedef vector<double> vd;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef map<int, int> mpii;
typedef long long ll;

int main() {
	int p, q, l, r;
	cin >> p >> q >> l >> r;
	vpii vp(p), vq(q);
	lp(i, p) {
		cin >> vp[i].first >> vp[i].second;
	}
	lp(i, q) {
		cin >> vq[i].first >> vq[i].second;
	}
	int ans[1004] = { 0 };
	lp(i, p) {
		lp(j, q) {
			int tmin = vp[i].first - vq[j].second, tmax = vp[i].second - vq[j].first;

			if (tmax < l || tmin > r)
				continue;

			lpi(k, max(l, tmin), min(tmax, r))
				ans[k] = 1;
		}
	}
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		if (ans[i]) cnt++;
	}
	cout << cnt;
	return 0;
}
