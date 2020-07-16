//https://codeforces.com/contest/287/problem/B

#include<iostream>
using namespace std;

typedef long long ll;


///int solve(int n)
ll sum(ll n)
{
	return n * (n + 1) / 2;
}
ll BS(ll n, ll k)
{
	ll st = 1;
	ll ed = k;
	ll sTemp = sum(ed);
	while (st < ed)
	{
		ll md = (st+ed) / 2;
		ll s = (md!=1)?sTemp-sum(md-1):sTemp;///sTemp - sum(md);
		if (s == n)
			return k - md + 1;
		if (s > n)
			st = md + 1;
		else
			ed = md;

	}
	return k - st + 2;

}

int main()
{
	ll n;
	ll k;
	cin >> n >> k;
	//int*arr = new int[k-1];
	if (n == 1)
		cout << 0;
	else if (k>= n)
		cout << 1;
	else if (sum(k-1) < n-1)
		cout <<-1;
	else
	{
		n--;
		k--;
		cout<<BS(n,k);
	}


	return 0;
}