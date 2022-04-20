// https://codeforces.com/contest/152/problem/B

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
	int n, m, k,curr,curc;
	cin >> n >> m >> curr >> curc >> k;
	vpii ks(k, pii(0, 0));
	lp(i, k)
		cin >> ks[i].first >> ks[i].second;
	ll moves = 0;
	rep(i,ks){
		int dx = ks[i].first, dy = ks[i].second;
		int xmove = 0, ymove = 0;
		if (dx > 0) {
			if (n - curr < dx)
				continue;
			xmove = (n - curr) / dx;
		}
		else if (dx < 0) {
			if (1 - curr > dx)
				continue;
			xmove = (1 - curr) / dx;
		}
		if (dy > 0) {
			if (m - curc < dy)
				continue;
			ymove = (m - curc) / dy;
		}
		else if (dy < 0) {
			if (1 - curc > dy)
				continue;
			ymove = (1 - curc) / dy;
		}
		int temp = (xmove && ymove) ? min(xmove, ymove) : xmove + ymove;
		moves += temp;
		if (xmove != 0) curr += temp * dx;
		if (ymove != 0) curc += temp * dy;
	}
	cout << moves;
	return 0;
}
