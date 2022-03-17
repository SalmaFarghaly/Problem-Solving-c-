// http://codeforces.com/contest/810/problem/B

#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
 
#define loop(i,n) for(int i =0;i<n;i++)
#define all(v) ((v).begin()),((v).end())
typedef long long ll;
 
struct day {
	int prod;
	int cus;
	day(int p, int c) {
		prod = p;
		cus = c;
	}
};
 
int main() {
	int n, f;
	cin >> n >> f;
	ll ans = 0;
	vector<day> days(n,day(0,0));
	loop(i, n) {
		cin >> days[i].prod >> days[i].cus;
		if (!days[i].prod || !days[i].cus) {
			days[i].prod = 0;
			days[i].cus = 0;
		}
		else if (days[i].prod >= days[i].cus) {
			ans += days[i].cus;
			days[i].prod = 0;
			days[i].cus = 0;
		}
	}
	sort(all(days), [](const day& d1, const day& d2) {
		return min(d1.cus,2*d1.prod) + min(d2.cus,d2.prod) > min(d2.cus,2*d2.prod) + min(d1.cus, d1.prod); // returns true if d1 > d2 for descending sort, returns true if d1 < d2 for ascending sort
	});
	loop(i, n) {
		ans += (i<f) ? min(2*days[i].prod, days[i].cus) : min(days[i].prod, days[i].cus);
	}
	cout << ans;
	return 0;
}
