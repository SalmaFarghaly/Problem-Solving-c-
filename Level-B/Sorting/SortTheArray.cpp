// https://codeforces.com/contest/451/problem/B

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

typedef long long ll;
typedef vector<int> vec;

#define all(v) ((v).begin()),((v).end())
#define loop(i,n) for(int i=0;i<n;i++)

int main() {
	int n;
	cin >> n;
	vec num(n, 0);
	loop(i, n)
		cin >> num[i];
	int l = -1, r = -1;
	int foundseg = 0;
	loop(i, n - 1) {
		if (num[i] > num[i + 1] && foundseg) {
			cout << "no";
			return 0;
		}
		if (num[i] > num[i + 1] && l == -1) {
			l = i;
			r = i + 1;
		}
		else if (num[i] > num[i + 1] && l != -1)
			r++;
		if (l != -1 && r != -1 && num[i] < num[i + 1])
			foundseg = 1;
	}
	if (r == -1 && l == -1)
		cout << "yes" <<endl<< 1<<" "<< 1;
	else if (((r + 1 < n && num[l] < num[r + 1]) || r + 1 == n) && (l == 0 || (l > 0 && num[r] > num[l - 1])))
		cout << "yes" << endl << l + 1 << " " << r + 1;
	else
		cout << "no";
	return 0;
}
