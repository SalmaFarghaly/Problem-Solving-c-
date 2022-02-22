//https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, c;

bool isValid (vector<int>& vec, int mid) {
	int tempC = c - 1;
	int st = vec[0] + mid;
	for (int i = 1; i < n && tempC !=0 ; i++) {
		if (st <= vec[i]) {
			st = vec[i] + mid;
			tempC--;
		}
	}
	return tempC == 0;
}

int main() {
	cin >> t; 
	while (t--) {
		cin >> n >> c;
		vector<int> vec(n,0);
		for (auto& ele : vec) {
			cin >> ele;
		}
		sort(vec.begin(),vec.end());
		int ed = vec[n-1] - vec[0];
		int st = 1;
		int mxmDis = -1;
		while (st <= ed) {
			int mid = (st + ed) / 2;
			if (isValid(vec, mid)) {
				mxmDis = max(mxmDis, mid);
				st = mid + 1;
			}
			else
				ed = mid - 1;
		}
		cout << mxmDis << endl;
	}
	return 0;
}
