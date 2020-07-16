//https://codeforces.com/contest/216/problem/B

#include<iostream>
#include<list>
#include<vector>
using namespace std;

enum status { PATH = 0,CYCLE=1};

status DFS(int cur,int parent,int &node_cnt,list<int>*adj,vector<int>&v)
{
	if (v[cur]==1)
		return CYCLE;
	v[cur] = 1;
	node_cnt++;
	for (auto it = adj[cur].begin();it != adj[cur].end();++it)
	{
		if (*it != parent)
		{
			if (DFS(*it, cur, node_cnt, adj, v) == CYCLE)
				return CYCLE;
		}
	
	}
	return PATH;
}
int main()
{
	int Nver;
	int Nedges;
	cin >> Nver >> Nedges;
	list<int>*adj = new list<int>[Nver];
	vector<int>vis(Nver,0);
	int u, v;
	for (int i = 0;i < Nedges;i++)
	{
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);

	}
	int TOREmove = 0;
	status s;
	for (int i = 0;i < Nver;i++)
	{
		int node_cnt = 0;
		if (vis[i] == 0)
		{
			s=DFS(i, -1, node_cnt, adj, vis);
			if(s==CYCLE&&node_cnt%2==1)
			TOREmove++;
		}
	}
	if ((Nver - TOREmove) % 2 == 1)
		TOREmove++;
	cout << TOREmove;
	return 0;
}