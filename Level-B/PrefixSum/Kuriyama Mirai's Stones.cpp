// http://codeforces.com/contest/433/problem/B

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

ll getSum(int l, int r,vlong &vec) {
	return vec[r] - vec[l - 1];
}

int main() {
	int n;
	cin >> n;
	vi vec(n + 1, 0);
	vi vecSorted(n + 1, 0);
	vlong sum(n+1,0);
	vlong sumSorted(n+1,0);
	loop(i, n) {
		cin >> vec[i];
		vecSorted[i] = vec[i];
	}
	sort(all(vecSorted));
	loop(i, n) {
		sum[i] = sum[i - 1] + vec[i];
		sumSorted[i] = sumSorted[i-1] + vecSorted[i];
	}
	int m;
	cin >> m;
	while (m--) {
		int l, r, type;
		cin >> type >> l >> r;
		if (type == 1) 
			cout << getSum(l, r, sum);
		else 
			cout << getSum(l, r, sumSorted);
		cout << endl;
	}
	return 0;
}
