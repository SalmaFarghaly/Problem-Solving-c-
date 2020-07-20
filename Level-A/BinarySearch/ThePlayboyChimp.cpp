//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552

#include<iostream>
using namespace std;

typedef long long ll;

int Shortest(int start, int end, ll*Harr, ll Qidx, int n)
{
	if (Harr[n-1] <= Qidx)return -1;
	int last = 0;
	int mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (start == end && Harr[start] > Qidx)
			return start;
		else if (Qidx < Harr[mid])
		{
			
			end = mid - 1;
			last = mid;
		}
		else
			start = mid + 1;
	}
	return last;
}

int Tallest(int start,int end,ll*Harr,ll Qidx,int n)
{
	if (Harr[0] >= Qidx)return -1;
	int last = 0;
	int mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (start == end && Harr[start] < Qidx)
			return start;
		else if (Qidx > Harr[mid])
		{
			start = mid + 1;
			last = mid;
		}
		else
			end = mid - 1;
	}
	return last;
}
/*int Tallest(int & last, int start, int end, int*Harr,int Qidx,int n)
{
	if (start==end&&Harr[start]<Qidx)
		return start;
	if (start >end)
		return -1;
	int mid = (start + end)/ 2;
	if (Qidx == Harr[mid])
		return mid - 1;
	else if (Qidx > Harr[mid])
		return Tallest(mid, mid + 1, end, Harr, Qidx, n);
	else if (Qidx < Harr[mid])
		return Tallest(mid, start, mid-1, Harr, Qidx, n);
}*/

int main()
{
	int n;
	cin >> n;
	ll*Harr = new ll[n];
	for (int i = 0;i < n;i++)
		cin >> Harr[i];
	int q;
	cin >> q;
	ll*Qarr = new ll[q];
	
	for (int i = 0;i < q;i++)
	{
		cin >> Qarr[i];
		int l=0;
		l = Tallest(0, n - 1, Harr, Qarr[i], n);
		if (l == -1) cout << "X ";
		else cout << Harr[l]<<" ";
		l = Shortest(0, n - 1, Harr, Qarr[i], n);
		if (l == -1) cout << 'X';
		else cout << Harr[l];
		cout << endl;

	}
	system("pause");
	return 0;
}