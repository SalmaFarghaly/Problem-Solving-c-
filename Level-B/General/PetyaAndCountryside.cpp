// https://codeforces.com/contest/66/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = -1;
	for (int i = 0; i < n; i++) {
		int j = i - 1;
		int k = i + 1;
		int cnt = 1;

		int prev = a[i], next = a[i];
		while (j >= 0 && prev >= a[j]) {
			cnt++;
			prev = a[j];
			j--;
		}
		while (k < n && next >= a[k]) {
			cnt++;
			next = a[k];
			k++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
