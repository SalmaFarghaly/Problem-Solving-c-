// http://codeforces.com/contest/584/problem/A

#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	if (t == 10) {
		if (n == 1) cout << -1;
		else cout << "1" + string(n - 1, '0');
	}
	else {
		string str (n,char(t+48));
		cout << str;
	}
	return 0;
}
