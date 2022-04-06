// https://codeforces.com/contest/287/problem/A

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
	char grid[4][4];
	memset(grid, ' ', sizeof(char) * 4 * 4);
	lp(i, 4) {
		lp(j, 4) {
			cin >> grid[i][j];
		}
	}
	lp(i, 3) {
		lp(j, 3) {
			string str = string() + grid[i][j] + grid[i][j + 1] + grid[i + 1][j] + grid[i + 1][j + 1];
			if (count(all(str), '.') <= 1 || count(all(str), '#') <= 1) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}
