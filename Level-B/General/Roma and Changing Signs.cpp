// https://codeforces.com/contest/262/problem/B
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
	int n, k;
	cin >> n >> k;
	vector<int> numbers(n,0);
	lp(i,n)
		cin >> numbers[i];
	for(int i=0;i<n && k!=0;i++,k--){
		if (numbers[i] < 0)
			numbers[i] *= -1;
		else
			break;
	}
	int ans = accumulate(all(numbers), 0);
	if (k > 0) {
		ans = (k % 2 == 0) ? ans : ans - numbers[n - 1];
	}
	cout << ans;
	return 0;
}
