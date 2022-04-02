// https://www.spoj.com/problems/TOE2/

#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

#define MP					make_pair

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<string, int> pii;

bool isWinState(string board, char c) {

	bool row = (board[0] == c && board[1] == c && board[2] == c) ||
			   (board[3] == c && board[4] == c && board[5] == c) ||
			   (board[6] == c && board[7] == c && board[8] == c);

	bool col= (board[0] == c && board[3] == c && board[6] == c) ||
			  (board[1] == c && board[4] == c && board[7] == c) ||
			 (board[2] == c && board[5] == c && board[8] == c);

	bool diagonal= (board[0] == c && board[4] == c && board[8] == c) ||
				   (board[2] == c && board[4] == c && board[6] == c);

	return row || col || diagonal;
}

void solWithBFS() {
	string target = "";

	while (true) {
		cin >> target;
		if (target == "end")
			break;

		string start = ".........", ans = "invalid", row;
		queue<pii> qu;
		qu.push(MP(start, 1));
		while (!qu.empty()) {
			string board = qu.front().first;
			int turn = qu.front().second;
			if (board == target && (isWinState(board,'O') || isWinState(board,'X') || target.find('.') == string::npos)) {
				ans = "valid";
				break;
			}
			if (isWinState(board, 'X') || isWinState(board, 'O')) {
				qu.pop();
				continue;
			}
			loop(i, 9) {
				if (board[i] == '.') {
					board[i] = (turn == 1) ? 'X' : 'O';
					if (board[i] == target[i]) {
						qu.push(MP(board, 1 - turn));
					}
					board[i] = '.';
				}
			}
			qu.pop();
		}
		cout << ans << endl;
	}
}

void solWOBFS() {
	string target = "";
	while (true) {
		cin >> target;
		if(target == "end")
			break;
		int count_x = count(target.begin(), target.end(), 'X');
		int count_o = count(target.begin(), target.end(), 'O');
		string ans = "valid";
		// number of X's on board at any time should be equal #O's or greater than #O's by exactly 1
		if (count_x - count_o > 1 || count_x < count_o)
			ans = "invalid";
		// X and O can't win at the same time
		else if (isWinState(target, 'X') && isWinState(target, 'O'))
			ans = "invalid";
		// if X is a win then #X's should be greater than #O's by 1
		else if (isWinState(target, 'X') && count_x - count_o != 1)
			ans = "invalid";
		// if O is a win then #X's should be equal to #O'ss
		else if (isWinState(target, 'O') && count_x != count_o)
			ans = "invalid";

		if (ans == "valid" && (isWinState(target, 'O') || isWinState(target, 'X') || count(all(target), '.') == 0)) {}
		else {
			ans = "invalid";
		}

		cout << ans << endl;
	}
}

int main() {

	// 1) solution with BFS
	solWithBFS();
	// 2) solution without BFS
	solWOBFS();
	return 0;
}
