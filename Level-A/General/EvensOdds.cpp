//http://codeforces.com/contest/318/problem/A

#include<iostream>
#include<math.h>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long evenPos = round((n+1) / 2) + 1;
	if (k == evenPos) {
		cout << 2;
	}
	else if( k > evenPos) {
		cout << 2 + (k-evenPos) * 2;
	}
	else {
		cout << 1 + (k-1) * 2;
	}
	return 0;
}
