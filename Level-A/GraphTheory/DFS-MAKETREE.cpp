//https://www.spoj.com/problems/MAKETREE/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<list>
using namespace std;
 
stack<int> st;
 
void setParent(list<int>* adj, vector<bool>& vis,int node) {
	vis[node] = 1;
	for (auto it = adj[node].begin(); it != adj[node].end(); ++it)
	{
		int index = *it;
		if (vis[*it] == 0)
			setParent(adj, vis, *it);
	}
	st.push(node);
}
 
void getHierarchy(list<int>* adj, vector<bool> & vis,int N) {
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			setParent(adj, vis,i);
		}
	}
	vector<int> parents(N,0);
	while (!st.empty()) {
		int p = st.top();
		st.pop();
		if (st.empty()) break;
		int c = st.top();
		parents[c] = p+1;
	}
	for (int i = 0; i < N; i++)
		cout << parents[i] << endl;
}
 
int main() {
	int N, K;
	cin >> N >> K;
	list<int>* adj = new list<int>[N];
	for (int i = 0; i < K; i++)
	{
		int j, u;
		cin >> j;
		while (j--) {
			cin >> u;
			adj[i].push_back(u - 1);
		}
	}
	vector<bool> vis(N,false);
	getHierarchy(adj,vis,N);
	return 0;
} 
