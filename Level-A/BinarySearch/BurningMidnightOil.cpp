//https://codeforces.com/contest/165/problem/B

#include<iostream>
using namespace std;
#include<algorithm>
 
int n;
int k;
 
bool isValid(int ele) {
	int pages = n-ele;
	int tempK = k;
	while (pages > 0 && floor(ele/tempK) != 0) {
		pages -= ele / tempK;
		tempK *= k;
	}
	return pages <= 0;
}
  
int main() {
	cin >> n >> k;
	int st = 1;
	int ed = n;
	int minValid = INT_MAX;
	while (st <= ed) {
		int mid = (st + ed) / 2;
		if (isValid(mid)) {
			minValid = min(minValid, mid);
			ed = mid - 1;
		}
		else {
			st = mid + 1;
		}
 
	}
	cout << minValid;
	return 0;
}
