// https://codeforces.com/contest/1665/problem/B
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
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> mp;
		lp(i, n) {
			int j;
			cin >> j;
			mp[j]++;
		}
		int max_count = -1;
		for (auto k : mp) {
			max_count = max(max_count, k.second);
		}
		int id = max_count, idd = max_count,coOp = 0,swapOp=0;
		while (idd != n) {
			if (idd * 2 > n) {
				swapOp += n - idd;
				idd = n;
			}
			else {
				swapOp += idd*2 - idd;
				idd *= 2;
			}
			coOp ++;
		}
		cout << coOp + swapOp<<endl;

	}
	return 0;
}
