// http://codeforces.com/contest/688/problem/B

#include<iostream>
#include<string>

using namespace std;

int main() {
	string n;
	cin >> n;
	n += string(n.rbegin(), n.rend());
	cout << n;
	return 0;
}
