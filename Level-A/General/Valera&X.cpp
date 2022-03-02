#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<string>
using namespace std;

typedef long long ll;
#define all(v) ((v).begin()),((v).end())
#define loop(i,n) for(int i=0;i<n;i++)
#define NO() cout<<"NO";return 0;

int main() {
	int n;
	cin >> n;
	vector<string> vec(n, "");
	loop(i, n) {
		cin >> vec[i];
	}
	char d = vec[0][0], a = vec[0][1];
	if (d == a) {
		NO()
	}
	loop(i, n) {
		loop(j, n) {
			if ((i == j || i + j == n - 1) && vec[i][j] != d) {
				NO()
			}
			else if( (i != j && i + j != n - 1) && vec[i][j] != a){
				NO()
			}
		}
	}
	cout << "YES";
	return 0;
}
