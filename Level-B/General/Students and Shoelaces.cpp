//https://codeforces.com/contest/129/problem/B

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
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef map<int, int> mpii;
typedef long long ll;
 
int main() {
	int n, m,s,t;
	cin >> n >> m;
	vector<set<int>> v(n);
	lp(i, m) {
		cin >> s >> t;
		v[s-1].insert(t-1);
		v[t-1].insert(s-1);
	}
	int ans = 0;
	while (1) {
		vector<int> r;
		lp(i, n) {
			if (v[i].size() == 1)
				r.push_back(i);
		}
		rep(i, r) {
			set<int>::iterator it = v[r[i]].begin();
			if (it != v[r[i]].end()) {
				v[*it].erase(r[i]);
				v[r[i]].clear();
			}
		}
		if (r.size())
			ans++;
		else
			break;
	}
	cout << ans;
	return 0;
}
