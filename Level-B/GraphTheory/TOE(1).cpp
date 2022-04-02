// https://www.spoj.com/problems/TOE1/

#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

#define loop(i,n) for(int i=0;i<n;i++)

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

int main() {

	int t;
	cin >> t;
  // 1) solution without BFS
	while (t--) {
		string target = "",row;
		loop(i, 3) {
			cin >> row;
			target += row;
		}
		int count_x = count(target.begin(), target.end(), 'X');
		int count_o = count(target.begin(), target.end(), 'O');
		string ans = "yes";
		if (count_x - count_o > 1 || count_x < count_o )
			ans = "no";
		else if (isWinState(target, 'X') && isWinState(target, 'O'))
			ans = "no";
		else if (isWinState(target, 'X') && count_x - count_o != 1)
			ans = "no";
		else if (isWinState(target, 'O') && count_x != count_o)
			ans = "no";
		cout << ans <<endl;
	}



	return 0;
}
