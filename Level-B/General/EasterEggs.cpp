// http://codeforces.com/contest/78/problem/B
#include<iostream>
#include<string>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)

int main() {
	int n;
	cin >> n;
	string str = "ROYGBIV" , ans;
	ans = str;
	int r = (n -7)/4 , e=(n-7)%4;
	loop(i, r) {
		ans += "GBIV";
	}
	ans += string("GBIV").substr(0, e);
	cout << ans;
	return 0;
}
