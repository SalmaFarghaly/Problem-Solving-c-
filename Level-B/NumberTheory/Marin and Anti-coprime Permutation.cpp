// https://codeforces.com/contest/1658/problem/B

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
#define loopO(i,n) for(int i=2;i<=n;i++)
 
int main() {
	int t;
	cin >> t;
	int mod = 998244353;
	while (t--) {
		int n;
		ll ans=1;
		cin >> n;
		if (n % 2 == 1) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i <= n / 2; i++) {
			ans = (ans * i) % mod;
			ans = (ans * i) % mod;
		}
		cout << ans<<endl;
	}
	return 0;
}
