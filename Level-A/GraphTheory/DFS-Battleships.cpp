//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104

/*#include<iostream>
using namespace std;

//r
//l
//u
void DFS_visit(int i,int j,char**adj, int**v, int n, char c, int &size,int m)
{
	size++;
	///if (size>m)
		////return;
	v[i][j] = 1;
	if (c == 'c')
	{
		if (j != 0)
		{
			if (adj[i][j - 1] == 'x'&&v[i][j - 1] == 0)
			{
				DFS_visit(i, j - 1, adj, v, n, 'l', size,m);
				return;
			}
		}
		if (i!=0)
		{
			if (adj[i - 1][j] == 'x'&&v[i - 1][j] == 0)
			{
				DFS_visit(i - 1, j, adj, v, n, 'u', size,m);
				return;
			}
		}
		if (j != n - 1)
		{
			if (adj[i][j + 1] == 'x'&&v[i][j + 1] == 0)
			{
				DFS_visit(i, j + 1, adj, v, n, 'r', size,m);
				return;
			}
		}
		if (i != n - 1)
		{
			if (adj[i + 1][j] == 'x'&&v[i + 1][j] == 0)
			{
				DFS_visit(i + 1, j, adj, v, n, 'd', size,m);
				return;
			}
		}
         
	}
	//i,j-1
	else if (c == 'l')
	{
		if (j != 0)
		{
			if (adj[i][j - 1] == 'x'&&v[i][j - 1] == 0)
				DFS_visit(i, j - 1, adj, v, n, 'l', size,m);
		}
	}
	//i,j+1
	else if (c == 'r')
	{
		if (j != n-1)
		{
			if (adj[i][j + 1] == 'x'&&v[i][j + 1] == 0)
				DFS_visit(i, j + 1, adj, v, n, 'r', size,m);
		}
	}
	//i-1,j
	else if (c == 'u')
	{
		if (i != 0)
		{
			if (adj[i-1][j] == 'x'&&v[i-1][j] == 0)
				DFS_visit(i-1, j, adj, v, n, 'u', size,m);
		}

	}
	//i+1,j
	else if (c == 'd')
	{
		if (i !=n-1 )
		{
			if (adj[i+1][j] == 'x'&&v[i+1][j] == 0)
				DFS_visit(i+1, j, adj, v, n, 'd', size,m);
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
		m= n / 2;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (adj[i][j] == 'x'&&v[i][j] == 0)
			{
				cnt++;
				DFS_visit(i,j,adj,v,n,c,s,m);
				s = 0;
			}
		}
	}
	//cout << cnt;
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
		cout<<"Case "<<k<<": "<< DFS(adj, visited, n)<<endl;
	}


	system("pause");
	return 0;
}*/
#include<iostream>
using namespace std;

//r
//l
//u
void DFS_visit(int i, int j, char**adj, int**v,int n)
{
	///size++;
	///if (size>m)
	////return;
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
	//cout << cnt;
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