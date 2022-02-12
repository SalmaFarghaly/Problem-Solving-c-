#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<stack>

stack<int> st;

void DFS(list<int>* adj, vector<bool>& vis, int node) {
	vis[node] = true;
	for (auto it = adj[node].begin(); it != adj[node].end(); it++) {
		if (!vis[*it])
			DFS(adj, vis, *it);
	}
	st.push(node);
}

int main() {
	int N = 1, M = 1;
		cin >> N >> M;
		list<int>* adj = new list<int>[N];
		while (M--) {
			int u, v;
			cin >> u >> v;
			adj[u - 1].push_back(v - 1);
		}
		vector<bool> vis(N, 0);
		for (int i = 0; i < N; i++) {
			if (!vis[i])
				DFS(adj, vis, i);
		}
		while (!st.empty()) {
			cout << st.top() + 1 << " ";
			st.pop();
		}
		cout << endl;
	return 0;
}
