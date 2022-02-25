//https://codeforces.com/contest/43/problem/A

#include<iostream>
#include<string.h>
using namespace std;

char team1[11] = "";
char team2[11] = "";
char team[11];

int score1 = 0;
int score2 = 0;

int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> team;
		if(strlen(team1)==0)
			strcpy_s(team1, team);
		else if(strlen(team2) == 0 && strcmp(team1, team) != 0)
			strcpy_s(team2, team);
		if (strcmp(team1, team) == 0)
			score1++;
		else
			score2++;
	}
	cout << ( score1 > score2 ? team1:team2);
	return 0;
}
