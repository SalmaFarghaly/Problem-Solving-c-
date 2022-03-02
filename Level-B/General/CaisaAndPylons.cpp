#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

typedef long long ll;
#define all(v) ((v).begin()),((v).end())
#define loop(i,n) for(int i=1;i<=n;i++)

int main() {
	int n;
	cin >> n;
	vector<int> v(n+1,0);
	loop(i, n) {
		cin >> v[i];
	}
	vector<int> vsub;
	adjacent_difference(all(v),back_inserter(vsub));
	ll e = 0, ans = 0;
	loop(j, n) {
		if (vsub[j] < 0) {
			e += abs(vsub[j]);
		}
		else if (vsub[j] > 0) {
			e -= vsub[j];
			if (e < 0) {
				ans += abs(e);
				e = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
