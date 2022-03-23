// http://codeforces.com/contest/88/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<queue>
#include<string>
#include <cctype>

#include<sstream>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define sz(v)  ((int)((v).size()))
#define loop(i,n) for(int i=0;i<n;i++)

typedef vector<int>::iterator vecIt;
typedef vector<int> vi;
typedef pair<int, int> pr;
typedef vector<pair<int,int>> vpr;

int n, m, x;
int q;
string str;
char keyboard[31][31];
bool can[26];

int dist(int i, int j, int shr, int shc)
{
	return (i - shr) * (i - shr) + (j - shc) * (j - shc);
}
bool canOne(pr letter,vpr & shifts) {
	loop(i, sz(shifts)) {
		if (dist(letter.first, letter.second, shifts[i].first, shifts[i].second) <= x*x) {
			return 1;
		}
	}
	return 0;
}

int main() {
	cin >> n >> m >> x;
	vpr kb[26];
	vpr shifts;
	loop(i, n) {
		loop(j, m) {
			char c;
			cin >> c;
			if (c == 'S')
				shifts.push_back(pr(i, j));
			else
				kb[c - 'a'].push_back(pr(i, j));
		}
	}
	loop(i, 26) {
		loop(j, sz(kb[i])) { // loop over letters in keyboard
			can[i] = canOne(kb[i][j],shifts);
			if (can[i])
				break;
		}
	}
	cin >> q;
	cin >> str;
	int ans = 0;
	loop(i, q) {
		char t = tolower(str[i]);
		if (!kb[t - 'a'].size()) {
			cout << -1;
			return 0;
		}
		if (!islower(str[i]) && !sz(shifts)) {
			cout << -1;
			return 0;
		}
		if (! islower(str[i]) && !can[t - 'a'])
			ans++;
	}
	cout << ans;
	return 0;
}
