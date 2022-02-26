https://codeforces.com/contest/680/problem/B

#include<iostream>
using namespace std;

int cities[101];

int main() {
	int n, a;
	cin >> n >> a;
	for (int i = 0; i < n; i++)
		cin >> cities[i];
	int cnt = (cities[a-1]) ? 1 : 0 ;
	int left = a - 2, right = a;
	while (left >= 0 || right < n) {
		if (left >= 0 && right < n && cities[left] && cities[right])
			cnt += 2;
		else if ( (left >= 0 && right >= n && cities[left]) || (right < n && left < 0 && cities[right]) )
			cnt += 1;
		left--;
		right++;
	}
	cout << cnt;
	return 0;
}
