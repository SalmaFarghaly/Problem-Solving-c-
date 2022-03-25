// https://codeforces.com/contest/785/problem/A

#include<iostream>
#include<string>
#include<map>
using namespace std;
 
typedef long long ll;
typedef map<string, int> mp;
 
mp p = {
	{"Tetrahedron",4},
	{"Cube",6},
	{"Octahedron",8},
	{"Dodecahedron",12},
	{"Icosahedron",20}
};
 
int main() {
	int n;
	cin >> n;
	int ans = 0;
	string str;
	while (n--) {
		cin >> str;
		ans += p[str];
	}
	cout << ans;
	return 0;
}
