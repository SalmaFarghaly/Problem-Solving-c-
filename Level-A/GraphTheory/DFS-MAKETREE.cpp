//https://www.spoj.com/problems/MAKETREE/

using namespace std;
#include<iostream>
#include<vector>
#include<list>
#include<stack>
 
 
 
stack<int> s;
 
void DFS_Visit(vector<int>&v, list<int>*adj,int src)
{
	v[src] = 1;
	for (auto it = adj[src].begin();it != adj[src].end();++it)
	{
		int index = *it;
		if (v[index] == 0)
			DFS_Visit(v,adj,index);
	}
	s.push(src);
 
}
 
 
int main()
{
	int n, k;
	cin >> n >> k;
	list<int> *adj = new list<int>[n];
	///int**vis = new int*[n];
	int w;
	int temp;
	for (int i = 0;i < k;i++)
	{
		cin >> w;
		for (int j = 0;j < w;j++)
		{
			cin >> temp;
			adj[i].push_back(temp - 1);
		}
	}
	vector<int>vis(n,0);
	for (int i = 0;i < n;i++)
	{
		if (vis[i] == 0)
			DFS_Visit(vis, adj, i);
	}
	vector<int>parent(n,-1);
	int l = s.top();
	s.pop();
	int t;
	while (!s.empty())
	{
		t = s.top();
		parent[t] = l;
		l = t;
		s.pop();
	}
 
	for (int i = 0;i < n;i++)
		cout << parent[i]+1 << endl;
 
	return 0;
}