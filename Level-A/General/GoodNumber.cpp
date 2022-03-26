// https://codeforces.com/contest/365/problem/A 

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

typedef long long ll;
typedef vector<int> vec;

#define all(v) ((v).begin()),((v).end())
#define loop(i,n) for(int i=0;i<n;i++)

int main() {
	int n,k;
	cin >> n >> k;
	int ans = 0;
	while (n--) {
		vec num(k+1,0);
		string nm;
		cin >> nm;
		loop(i, nm.length()) {
			if (nm[i] - '0' <= k) {
				num[nm[i] - '0'] = 1;
			}
		}
		if (all_of(all(num), [](int i) {return i == 1; }))
			ans++;
	}
	cout << ans;
	return 0;
}
