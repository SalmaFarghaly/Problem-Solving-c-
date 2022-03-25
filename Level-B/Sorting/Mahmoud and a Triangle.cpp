// https://codeforces.com/contest/766/problem/B

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<climits>
 
using namespace std;
 
typedef long long ll;
typedef map<string, int> mp;
typedef vector<int> vec;
 
#define all(v) ((v).begin()),((v).end())
#define loop(i,n) for(int i=0;i<n;i++)
 
int main() {
	int n;
	cin >> n;
	vec v(n, 0);
	loop(i, n) {
		cin >> v[i];
	}
	sort(all(v));
	int ed = n - 1;
	int st = ed - 2;
	while (st >= 0) {
		if (v[ed] + v[ed - 1] > v[st] && v[ed] + v[st] > v[ed - 1] && v[ed - 1] + v[st] > v[ed]) {
			cout << "YES";
			return 0;
		}
		st--;
		ed--;
	}
	cout << "NO";
	return 0;
}
