#include<iostream>
#include<vector>
#include<list>
using namespace std;

bool DFS(list<int>* adj, vector<int>& black,vector<int>& grey, int n, int node) {
	grey[node] = 1;
	for (auto it = adj[node].begin(); it != adj[node].end(); it++) {
		if (grey[*it]) {
				return true;
		}
		else if(! black[*it]) {
			if (DFS(adj, black, grey, n, *it))
				return true;
		}
	}
	black[node] = 1;
	grey[node] = 0;
	return false;
}

int containsCycle(list<int>* adj, int n) {
	vector<int> black(n, 0);
	vector<int> grey(n,0);
	for (int i = 0; i < n; i++) {
		if (black[i] == 0 && grey[i] == 0) {
			if(DFS(adj, black,grey, n,i))
				return 1;
		}
	}
	return 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	list<int>* adj = new list<int>[n];
	int u, v;
	while (m--) {
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
	}
	cout << containsCycle(adj,n);
	return 0;
}
