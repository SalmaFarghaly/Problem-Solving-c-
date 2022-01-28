//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=288

#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std;

char grid[30][30];
bool visited[30][30];

int n;
int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,-1,1,-1,-1,1,1};

void DFS(int i,int j) {
	
	visited[i][j] = true;
	for (int k = 0; k < 8; k++) {
		if (0 <= i + dx[k] && i + dx[k] < n && 0 <= j + dy[k] && j + dy[k] < n) {
			if(!visited[i+dx[k]][j+dy[k]] && grid[i + dx[k]][j + dy[k]] == '1')
			DFS(i + dx[k], j + dy[k]);
		}
	}
}

int connectedComp() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && grid[i][j]=='1') {
				DFS(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int img = 0;
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
		{
			cin >> grid[i];
		}
		printf("Image number %d contains %d war eagles.\n", ++img, connectedComp());
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}
