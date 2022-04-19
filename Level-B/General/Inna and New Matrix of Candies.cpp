// https://codeforces.com/contest/400/problem/B

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
typedef vector<string> vs;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef long long ll;

int main() {
	int n,m;
	cin >> n >> m;
	vs grid(n,"");
	vi dis (n, 0);
	lp(i, n) {
		cin >> grid[i];
		int temp = grid[i].find('S') - grid[i].find('G');
		int t2 = m - grid[i].find('G') - 1;
		dis[i] = (temp < t2) ? temp : t2;
	}
	if (any_of(all(dis), [](int i) {return i < 0; })) {
		cout << "-1";
	}
	else {
		int moves = 0;
		while (any_of(all(dis), [](int i) {return i != 0; })) {
			int mnm = INT_MAX;
			rep(i, dis) 
				if (dis[i] !=0 ) mnm = min(mnm, dis[i]);
			rep(i, dis)
				if (dis[i] != 0) dis[i] -= mnm;
			moves++;
		}
		cout << moves;
	}
	return 0;
}
