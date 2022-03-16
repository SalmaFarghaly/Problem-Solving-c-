// http://codeforces.com/contest/6/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

#include<sstream>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define sz(v)  ((int)((v).size()))
#define loop(i,n) for(int i =0;i<n;i++)

typedef long long ll;
typedef vector<int>::iterator vecIt;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vector<char>> vecGrid;
typedef vector<vector<int>> vecVis;
typedef vector<ll> vlong;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int n, m, pi = -1, pj = -1;
char c;

void DFS(vecGrid & grid,vecVis & vis,int x,int y, int & ans) {
	vis[x][y] = 1;
	loop(i, 4) {
		if (0 <= x + dx[i] && x + dx[i] < n && 0 <= y + dy[i] && y + dy[i] < m && !vis[x + dx[i]][y + dy[i]] && 
			grid[x + dx[i]][y + dy[i]] != '.' && (grid[x][y] == c || grid[x][y] == grid[x + dx[i]][y + dy[i]]) ) {
			DFS(grid, vis ,x + dx[i], y + dy[i] , ans);
			if (grid[x][y] == c && grid[x + dx[i]][y + dy[i]] != c)
					ans++;
		}
	}
}

int main() {
	cin >> n >> m >> c;
	vecGrid grid(n,vc(m,'.'));
	loop(i, n) {
		loop(j, m) {
			cin >> grid[i][j];
			if (grid[i][j] == c && pi == -1 && pj == -1) {
				pi = i;
				pj = j;
			}
		}
	}
	vecVis vis (n, vi(m, 0));
	int ans = 0;
	DFS(grid,vis,pi,pj,ans);
	cout << ans;
	return 0;
}
