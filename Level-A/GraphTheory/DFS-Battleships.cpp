//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N;
int T;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool explore(vector<string>& grid, vector<vector<bool>>& vis, int i, int j, bool alive, int dir = -1, int s = 1) {
	vis[i][j] = true;
	if (s == N / 2) return alive;
	if (dir == -1) {
		for (int k = 0; k < 4; k++) {
			if (i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < N) {
				if (!vis[i + dx[k]][j + dy[k]] && grid[i + dx[k]][j + dy[k]] != '.') {
					alive = explore(grid, vis, i + dx[k], j + dy[k],grid[i + dx[k]][j + dy[k]]=='x', k, ++s) || alive;
					break;
				}
			}
		}
	}
	else {
		if (i + dx[dir] >= 0 && i + dx[dir] < N && j + dy[dir] >= 0 && j + dy[dir] < N) {
			if (!vis[i + dx[dir]][j + dy[dir]] && grid[i + dx[dir]][j + dy[dir]] != '.') {
				alive = explore(grid, vis, i + dx[dir], j + dy[dir],grid[i + dx[dir]][j + dy[dir]] == 'x', dir, ++s) || alive;
			}
		}
	}
	return alive;
}

int getAliveShipsCnt(vector<string> & grid, vector<vector<bool>> & vis) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j] && grid[i][j] !='.' && explore(grid, vis, i, j, grid[i][j] == 'x'))
				cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> T;
	int i = 0;
	while (T--) {
		i++;
		cin >> N;
		vector<string> grid(N,"");
		vector<vector<bool>> vis(N,vector<bool>(N,0));
		for (auto& ele : grid) {
			cin >> ele;
		}
		printf("Case %d: %d\n",i ,getAliveShipsCnt(grid, vis));

	}
}
