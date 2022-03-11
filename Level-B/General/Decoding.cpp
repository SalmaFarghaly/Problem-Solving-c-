// http://codeforces.com/contest/746/problem/B
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str, ans="";
	cin >> str;
	ans = str[0];
	if (n % 2) {
		for (int i = 1; i < n; i++) {
			ans = str[i] + ans;
			if (i < n - 1)
				ans += str[++i];
		}
	}
	else {
		for (int i = 1; i < n; i++) {
			ans += str[i];
			if (i < n - 1)
				ans = str[++i] + ans;
		}
	}
	cout << ans;
	return 0;
}
