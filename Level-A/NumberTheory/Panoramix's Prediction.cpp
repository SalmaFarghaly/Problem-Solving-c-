// https://codeforces.com/contest/80/problem/A

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
 
using namespace std;
 
typedef long long ll;
typedef map<string, int> mp;
typedef vector<int> vec;
 
#define all(v) ((v).begin()),((v).end())
 
int main() {
	int n,m;
	cin >> n >> m;
	vec primes= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	if (n == 47) {
		cout << "NO";
	}
	else if (m == primes [find(all(primes), n) - primes.begin()+1]) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
