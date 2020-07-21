//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1393

using namespace std;
#include<iostream>
///"IEHOVA"
void DFS_Visit(int**v,char**adj, int isrc, int jsrc, int ides, int jdes)
{
	if (isrc == ides && jsrc == jdes)
		return;
	v[isrc][jsrc] = 1;
	if(adj[isrc][jsrc]!='@')
	cout << " ";
	if (adj[isrc][jsrc + 1] == 'I' || adj[isrc][jsrc + 1] == 'E' || adj[isrc][jsrc + 1] == 'H' || adj[isrc][jsrc + 1] == 'O'
		|| adj[isrc][jsrc + 1] == 'V' || adj[isrc][jsrc + 1] == 'A' || adj[isrc][jsrc + 1] == '#')
	{
		if (v[isrc][jsrc + 1] == 0)
		{
			cout << "right";
			DFS_Visit(v, adj, isrc, jsrc + 1, ides, jdes);
			return;
		}
	}
	if (adj[isrc][jsrc -1] == 'I' || adj[isrc][jsrc - 1] == 'E' || adj[isrc][jsrc - 1] == 'H' || adj[isrc][jsrc - 1] == 'O'
		|| adj[isrc][jsrc - 1] == 'V' || adj[isrc][jsrc - 1] == 'A' || adj[isrc][jsrc - 1] == '#')
	{
		if (v[isrc][jsrc - 1] == 0)
		{
			cout << "left";
			DFS_Visit(v, adj, isrc, jsrc - 1, ides, jdes);
			return;
		}
	}
	if (adj[isrc-1][jsrc] == 'I' || adj[isrc-1][jsrc] == 'E' || adj[isrc-1][jsrc] == 'H' || adj[isrc-1][jsrc] == 'O'
		|| adj[isrc-1][jsrc] == 'V' || adj[isrc-1][jsrc] == 'A' || adj[isrc-1][jsrc] == '#')
	{
		if (v[isrc - 1][jsrc]==0)
		{
			cout << "forth";
			DFS_Visit(v, adj, isrc - 1, jsrc, ides, jdes);
			return;
		}
	}

}



int main()
{
	int t;
	cin >> t;
	int n, m;
	while (t--)
	{
		cin >> n >> m;
		char**adj = new char*[n];
		int**visited = new int*[n];
		for (int i = 0;i < n;i++)
		{
			adj[i] = new char[m];
			visited[i] = new int[m];
		}
		int isrc, jsrc, ides, jdes;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				cin >> adj[i][j];
				visited[i][j] = 0;
				if (adj[i][j] == '@')
				{
					isrc = i;jsrc = j;
				}
				if (adj[i][j] == '#')
				{
					ides = i;jdes = j;
				}
			}
		}
		DFS_Visit(visited,adj,isrc,jsrc,ides,jdes);
		cout << endl;
	}
	system("pause");
	return 0;
}
