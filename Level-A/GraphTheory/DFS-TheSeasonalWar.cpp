//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=288

using namespace std;
#include<iostream>
#include<fstream>
#include<list>
#include<string>

struct Node
{
	int index;
	int visited;
};
void DFS_visit(int i,int j,int**adj,int**v,int n)
{
	//if (i == n || i < 0 || j == n || j < 0)
		////return;
	v[i][j] = 1;
	if (i != 0 && j != 0)
	{
		if (adj[i - 1][j - 1] == 1&&v[i-1][j-1]==0)
			DFS_visit(i - 1, j - 1, adj, v, n);
	}
	if (i != 0 )
	{
		if (adj[i - 1][j] == 1&&v[i-1][j]==0)
			DFS_visit(i - 1, j, adj, v, n);
	}
	if (i!=0&&j!=n-1)
	{
		if (adj[i - 1][j + 1] == 1&&v[i-1][j+1]==0)
			DFS_visit(i - 1, j + 1, adj, v, n);
	}
	if (j != 0)
	{
		if (adj[i][j - 1] == 1&&v[i][j-1]==0)
			DFS_visit(i, j - 1, adj, v, n);
	}
	if (j!=0&&i!=n-1)
	{
		if (adj[i + 1][j - 1] == 1&&v[i+1][j-1]==0)
			DFS_visit(i + 1, j - 1, adj, v, n);
	}
	if (j != n - 1)
	{
		if (adj[i][j + 1] == 1&&v[i][j+1]==0)
			DFS_visit(i, j + 1, adj, v, n);
	}
	if (i != n - 1)
	{
		if (adj[i + 1][j] == 1&&v[i+1][j]==0)
			DFS_visit(i + 1, j, adj, v, n);
	}
	if (i != n - 1 && j != n - 1)
	{
		if (adj[i + 1][j + 1] == 1&&v[i+1][j+1]==0)
			DFS_visit(i + 1, j + 1, adj, v, n);
	}

}
int DFS(int**v,int**adj,int n)
{
	int cnt = 0;
	///Node*arr = new Node[n];
	/*for (int i = 0;i < n;i++)
	{
		arr[i].index = i;
		arr[i].visited = 0;
	}*/
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (v[i][j] == 0&&adj[i][j]==1)
			{
				v[i][j] = 1;
				DFS_visit(i,j,adj,v,n);
				cnt++;
			}

		}
		/*if (arr[i].visited == 0)
		{
			    arr[i].visited = 1;
			    DFS_visit(&arr[i],adj,arr);
		        cnt++;
	    }*/
	}
	return cnt;
}

int main()
{
	int n;
	int i = 1;
	while (cin >> n)
	{
		////list<int>*adj = new list<int>[n];
		int u, v;
		ifstream infile;
		///Node temp;
		///temp.visited = 0;
		int t;
		string str;
		int**adj = new int*[n];
		int**visited = new int*[n];
		for (int i = 0;i < n;i++)
		{
			adj[i] = new int[n];
			visited[i] = new int[n];
		}
		for (int i = 0;i < n;i++)
		{
			cin >> str;
			for (int j = 0;j < n;j++)
			{
				///	temp.index = j;
				if (str[j] == '1')
					adj[i][j] = 1;
				visited[i][j] = 0;
			}
			///adj[v].push_back(u);
		}
		///Image number 1 contains 3 war eagles.
			///Image number 2 contains 6 war eagles.
			cout << "Image number " << i << " contains " << DFS(visited, adj, n) << " war eagles." << endl;
			i++;
	}
	system("pause");


	return 0;
}