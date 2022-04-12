// https://codeforces.com/contest/714/problem/B

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
	int n;
	int a = -1, b = -1, c = -1;
	cin >> n;
	lp(i, n) {
		int t; cin >> t;
		if (a == -1) a = t;
		else if (b == -1 && a != t) b = t;
		else if (c == -1 && a != t && b != t) c = t;
		else if (a != t && b != t && c != t) {
			cout << "NO";
			return 0;
		}
	}
	vector<int> v = { a,b,c};
	sort(all(v));
	if (a != -1 && b != -1 && c != -1) {
		cout << ( v[1]-v[0] == v[2]-v[1] ? "YES":"NO");
	}
	else {
		cout << "YES";
	}
	return 0;
}
