// https://codeforces.com/contest/476/problem/B

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
#define rep(i, v)		for(int i=1;i<sz(v);++i)
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

void factorial(vd & v) {
	rep(i, v) {
		v[i] = v[i - 1] * i;
	}
}

int main() {
	string org , dest;
	cin >> org >> dest;
	int pO = count(all(org), '+'), pD = count(all(dest), '+');
	int mO = count(all(org), '-'), mD = count(all(dest), '-');
	int qD = count(all(dest), '?');
	if (qD == 0)
		cout << ( (pO == pD && mO == mD) ? 1.0 : 0);
	else if(pD > pO || mD > mO){
		cout << 0;
	}
	else {
		vd v(org.length() + 1, 1.0);
		factorial(v);
		int l = pO - pD;
		double prob = v[qD] / (double)(v[l] * v[qD - l]);
		printf("%0.12f", prob/ double(pow(2, qD)));
	}
	return 0;
}
