// https://codeforces.com/contest/218/problem/A

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
	int arr[202],ansArr[202];
	int n, k;
	cin >> n >> k;
	clr(arr, 0);
	clr(ansArr, 0);
	lp(i, 2 * n + 1) {
		cin >> arr[i];
		ansArr[i] = arr[i];
	}
	for (int i = 1; i < 2 * n + 1 && k > 0; i += 2) {
		if (arr[i] - 1 > arr[i + 1] && arr[i] - 1 > arr[i - 1]) {
			k--;
			ansArr[i]--;
		}
	}
	lp(i, 2 * n + 1) {
		cout << ansArr[i] << " ";
	}
	return 0;
}
