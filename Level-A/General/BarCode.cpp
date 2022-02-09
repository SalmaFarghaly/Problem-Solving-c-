// http://codeforces.com/contest/225/problem/C

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>A;
int n, m,x,y;

int minPaints(int curRow,int curCol,int aboveCell,int seq) {
	if (curRow >= n || curCol >= m && seq < x || seq > y) return INT_MAX;
	if (curRow >=n || curCol >=m ) return 0;
	int mnm = INT_MAX;

	
	if (aboveCell != A[curRow][curCol] && seq < y ) {
		A[curRow][curCol] = aboveCell;
		mnm = min(mnm, 1 + minPaints(curRow, curCol, aboveCell,seq+1));
		A[curRow][curCol] = !aboveCell;
	}
	else
		mnm = minPaints(curRow,curCol,A[curRow][curCol],seq+1);
	
	return mnm;
}

int main() {
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++) {
		vector<int>vec(m,0);
		for (int j = 0; j < m; j++) {
			char temp; cin >> temp;
			if (temp == '#') vec[i] = 1 ;
			else vec[i] = 0;
		}
		A.push_back(vec);
	}
	cout << minPaints(0,0,A[0][0],1);
	return 0;
}
