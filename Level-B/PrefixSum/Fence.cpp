// http://codeforces.com/contest/363/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

#include<sstream>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define sz(v)  ((int)((v).size()))
#define loop(i,n) for(int i =1;i<=n;i++)
#define loopZero(i,n) for(int i =0;i<n;i++)

typedef long long ll;
typedef vector<int>::iterator vecIt;
typedef vector<int> vi;
typedef vector<ll> vlong;

int main() {
	int n,k;
	cin >> n >> k;
	vi v(n, 0);
	loopZero(i, n) {
		cin >> v[i];
	}
	int st = 0, ed = k - 1;
	ll mnm = accumulate(v.begin(),v.begin()+k, 0);
	ll sum = mnm;
	int ans = 0;
	while (ed != n - 1) {
		sum = sum - v[st++] + v[++ed];
		ans = (mnm > sum) ? st : ans;
		mnm = min(mnm, sum);
	}
	cout << ++ans;
	return 0;
}
