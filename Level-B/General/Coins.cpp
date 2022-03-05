//https://codeforces.com/contest/47/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include <map>
#include<string>
using namespace std;

typedef long long ll;
typedef map<char,string> mpp;
typedef map<char,string>::iterator mppit;
#define all(v) ((v).begin()),((v).end())
#define loop(i,n) for(int i=0;i<n;i++)

int main() {
	string str;
	string letters = "ABC";
	mpp mp;
	loop(i, 3) { // g - letter - s
		mp[letters[i]] = ' ';
		mp[letters[i]] += letters[i];
		mp[letters[i]] += ' ';
	}
	loop(i, 3) {
		cin >> str;
		if (str[1] == '<') {
			mp[str[0]][0] = str[2];
			mp[str[2]][2] = str[0];
		}
		else {
			mp[str[0]][2] = str[2];
			mp[str[2]][0] = str[0];
		}
	}
	int s = 0, g = 0;
	mppit found;
	for (mppit it = mp.begin(); it != mp.end(); it++) {
		if (it->second[0] == ' ' && g == 0) 
			g ++;
		else if (it->second[2] == ' ' && s == 0)
			s ++;
		else if (it->second[2] != ' ' && it->second[0] != ' ')
			found = it;
	}
	if (g == 1 && s == 1)
		cout << found->second[2]<<found->first << found->second[0];
	else
		cout << "Impossible";
	return 0;
}
