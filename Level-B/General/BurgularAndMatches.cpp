#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<pair<int, int>> vpair;
typedef pair<int, int> pi;
typedef long long ll;

int main() {
	int n, m, a, b;
	cin >> n >> m;
	vpair vec(m,pi(0,0));
	for (int i = 0; i < m; i++) {
		cin >> vec[i].first;
		cin >> vec[i].second;
	}
	sort(vec.begin(), vec.end(), [](const pi& p1, const pi& p2) {
		return p1.second > p2.second;
	});
	ll ans = 0;
	int j = 0;
	while (n > 0 && j < m) {
		ans += min(vec[j].first, n)*vec[j].second;
		n -= min(vec[j].first, n);
		j++;
	}
	cout << ans;
	return 0;
}
