// https://codeforces.com/contest/242/problem/C

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
#define lim					1000000000

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef map<pair<int, int>,pair<int,int>> mpii; // map pair to (visited,allowed)
typedef queue<pair<int, int>> quii;
typedef long long ll;

int dx [] = {1,-1,0,0,1,-1,1,-1};
int dy [] = {0,0,1,-1,-1,-1,1,1};

int main() {
	int str, stc, edr, edc,n;
	cin >> str >> stc >> edr >> edc>>n;
	mpii mp;
	while (n--) {
		int r, c1, c2;
		cin >> r >> c1 >> c2;
		lpi(i, c1, c2) {
			if (mp.count(MP(r, i)) == 0)
				mp[MP(r, i)] = MP(0, 1);
		}
	}
	quii qu;
	qu.push(MP(str, stc));
	int dep = 0,sz = 1;
	for( ; !qu.empty() ; ++dep , sz = qu.size()){
		while (sz--) {
			int curr = qu.front().first, curc = qu.front().second;
			if (curr == edr && curc == edc) {
				cout << dep;
				return 0;
			}
			lp(i, 8) {
				if (dx[i] + curr >= 0 && dx[i] + curr <= lim && dy[i] + curc >= 0 && dy[i] + curc <= lim &&
						mp.count(MP(dx[i] + curr, dy[i] + curc)) != 0 && mp[MP(dx[i] + curr, dy[i] + curc)].first == 0) {
						mp[MP(dx[i] + curr, dy[i] + curc)].first = 1;
						qu.push(MP(dx[i] + curr, dy[i] + curc));
				}
			}
			qu.pop();
		}
	}
	cout << -1;
	return 0;
}
