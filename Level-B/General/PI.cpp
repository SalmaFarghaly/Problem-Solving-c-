//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=353

using namespace std;
#include<vector>
#include<iostream>
#include <iomanip>
#include<cmath>

int temp = 0;
int combinationsCnt = 0;


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b,a%b);
}
int solve(vector<int>&vec,int & N) {
	int cnt = 0;
	for (int i = 0;i < N-1;i++) {
		for (int j = i + 1;j < N;j++) {
			if (vec[i] > vec[j]) {
				if (gcd(vec[i], vec[j]) == 1)
					cnt++;
			}
			else {
				if (gcd(vec[j], vec[i]) == 1)
					cnt++;
			}

		}
	}
	return cnt;
}
int main() {
	int N = 0;
	cin >> N;
	while (N != 0) {
		vector<int >vec;
		combinationsCnt = N * (N - 1)/2;
		for (int i = 0;i < N;i++)
		{
			cin >> temp;
			vec.push_back(temp);
		}
			int m=solve(vec,N);
			double ans = 0;
			if (m != 0)
			{
				ans = sqrt(combinationsCnt * 6.000000 / m);
				cout << setprecision(6) << fixed << ans <<endl;
			}
			else
			{
				cout << "No estimate for this data set." << endl;
			}
			
		
		cin >> N;
	}

	system("pause");
	return 0;
}