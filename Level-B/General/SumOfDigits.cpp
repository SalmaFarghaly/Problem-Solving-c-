//https://codeforces.com/contest/102/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
using namespace std;

typedef long long ll;
#define all(v) ((v).begin()),((v).end())
#define loop(i,n) for(int i=0;i<n;i++)

int main() {
	string str;
	cin >> str;
	int cnt = 0, s = 0, sum = 0;
	while (str.length()>=2) {
		sum = 0;
		loop(i, str.length()) {
			sum += str[i] - '0';
		}
		cnt++;
		str = to_string(sum);
	}
	cout << cnt;
	return 0;
}
