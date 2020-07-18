//https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
int nStalls;
int Cows;
ll lo;
ll hi;

int IsValid(vector<ll>&vec,ll dist)
{
	int cnt = 1;
	ll st = vec[0];
	int i = 1;
	while (cnt < Cows&&i<nStalls)
	{
		if (vec[i]-st >=dist)
		{
			cnt++;
			st = vec[i];
		}
		i++;
	}
	if (i == nStalls&&cnt!=Cows)return 0;
	else return 1;                                  

}

int main()
{
	int t;
	cin >> t;
	ll temp;
	while (t--)
	{
		cin >> nStalls >> Cows;
		vector<ll>vec;
		for (int i = 0;i < nStalls;i++)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(),vec.end());
		ll md;
		lo = 0;
		hi = vec[nStalls-1];
		ll lastvalid=0;
		while (lo < hi)
		{
			md = (lo + hi) / 2;
			if (IsValid(vec,md))
				{
			    lo = md+1;
				lastvalid=md;
				}
			else
				hi = md - 1;
		}
		if(lastvalid<hi&&IsValid(vec,hi))
			cout<<hi<<endl;
		else
		   cout<<lastvalid<<endl;

	}
	return 0;
}