//https://codeforces.com/contest/165/problem/B

#include<iostream>
#include<climits>
using namespace std;

typedef long long ll;


int isValid(ll n,ll v,int k)
{
	int p = 0;
	ll cnt = 0;
	ll result =pow(k,p);
	while (v>=result&&cnt<n)
	{
		cnt+=v/result;
		p++;
		result = pow(k, p);
	}
	if (cnt >= n)
		return 1;
	else
		return 0;
}
ll BS(ll n,int k)
{
	ll lastvalid = INT_MAX;
	ll st = 1;
	ll ed = n;
	ll md;
	while (st<ed)
	{
		md = (st + ed) / 2;
		int Cnt=isValid(n,md,k);
		if (Cnt == 0)
			st = md + 1;
		else
		{
			ed = md - 1;
			lastvalid = md;
		}
	}
	if (isValid(n, st, k) && lastvalid > st)
		return st;
	else
	    return lastvalid;
}

int main()
{
	ll n;
	int k;
	cin >> n >> k;
	if (n == 1)cout << 1;
	else cout<<BS(n,k);
	return 0;
}