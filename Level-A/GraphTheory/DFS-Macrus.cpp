//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1393

#include<iostream>
#include<vector>
#include<string>

using namespace std;

string str = "IEHOVA";
int dx[] = {0,0,-1};
int dy[]= {1,-1,0};
string directions[] = {"right","left","forth"};
int row, col;

void getPath(vector<vector<char>> & grid, vector<vector<bool>>& vis,int  r , int  c , int & k) {
	for (int i = 0; i < 3; i++) {
		if (c + dy[i] >= 0 && c + dy[i] < col && r + dx[i] >=0 ) {
			if (grid[r + dx[i]][c + dy[i]] == '#') {
				cout << directions[i] << endl;
				return;
			}
			else if (grid[r + dx[i]][c + dy[i]] == str[k] && !vis[r + dx[i]][c + dy[i]]) {
				vis[r + dx[i]][c + dy[i]] = true;
				cout << directions[i] << " ";
				getPath(grid, vis, r + dx[i], c + dy[i], ++k);
				break;
			}
		}
	}

}

int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> row >> col;
		char src = '@', dest = '#';
		int rsrc = 0, csrc = 0;
		int k = 0;
		vector<vector<char>> grid(row, vector<char>(col, ' '));
		vector<vector<bool>> vis(row, vector<bool>(col, false));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == '@') {
					rsrc = i; csrc = j;
				}
			}
		}
		getPath(grid, vis, rsrc, csrc, k);
		vis[rsrc][csrc] = true;
	}
	return 0;
}
