//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104

#include<iostream>
using namespace std;

void DFS_visit(int i, int j, char**adj, int**v,int n)
{
	    v[i][j] = 1;
		if (j != 0)
		{
			if (adj[i][j - 1] != '.'&&v[i][j - 1] == 0)
			{
				DFS_visit(i, j - 1, adj, v, n);
			}
		}
		if (j != n - 1)
		{
			if (adj[i][j + 1] != '.'&&v[i][j + 1] == 0)
			{
				DFS_visit(i, j + 1, adj, v, n);
			}
		}
		if (i != 0)
		{
			if (adj[i - 1][j] != '.'&&v[i - 1][j] == 0)
			{
				DFS_visit(i - 1, j, adj, v, n);
			}
		}
		if (i != n - 1)
		{
			if (adj[i + 1][j] != '.'&&v[i + 1][j] == 0)
			{
				DFS_visit(i + 1, j, adj, v, n);
			}
		}

}




int DFS(char**adj, int**v, int n)
{
	int cnt = 0;
	char c = 'c';
	int s = 0;
	int m;
	if (n % 2 == 1)
		m = n / 2 + 1;
	else
		m = n / 2;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (adj[i][j] == 'x'&&v[i][j] == 0)
			{
				cnt++;
				DFS_visit(i, j, adj, v, n);
				s = 0;
			}
		}
	}
	return cnt;
}

int main()
{
	int t;
	cin >> t;
	int n;
	int k = 0;
	while (t--)
	{
		cin >> n;
		char**adj = new char*[n];
		int**visited = new int*[n];
		for (int i = 0;i < n;i++)
		{
			adj[i] = new char[n];
			visited[i] = new int[n];
		}
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				cin >> adj[i][j];
				visited[i][j] = 0;
			}
		}
		k++;
		cout << "Case " << k << ": " << DFS(adj, visited, n) << endl;
	}


	system("pause");
	return 0;
}
