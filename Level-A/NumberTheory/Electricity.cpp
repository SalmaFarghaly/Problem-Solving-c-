//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3300

#include<iostream>
using namespace std;

int arr[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
void NextDate(int D, int M, int Y, int C, int&ND, int&NM, int&NY)
{
	if (Y % 4 == 0 && Y % 100 != 0)
		arr[2] = 29;
	if (D == arr[M])
	{
		ND = 1;
		if (M == 12)
		{
			NM = 1;
			NY=Y+1;
		}
		else
		{
			NM=M+1;
			NY=Y;
		}
	}
	else
	{		ND=D+1;
	        NM = M;
	        NY = Y;
     }
	arr[2] = 28;
}

int main()
{
	int Ndates;
	while (cin >> Ndates)
	{
		if (Ndates == 0)
			break;
		int D, M, Y, C;
		int ND=0, NM=0, NY=0, NC=0;
		int cmb = 0;
		int cnt = 0;
		int lastComb = 0;
		for (int i = 0;i < Ndates;i++)
		{
			cin >> D >> M >> Y >> C;
			if (D == ND && Y == NY && M == NM && i != 0)
			{
				cnt++;
				cmb = cmb + C - lastComb;
			}
			if (i != Ndates - 1)
			{
				NextDate(D, M, Y, C, ND, NM, NY);
				lastComb = C;
			}
		}
		cout << cnt << " " << cmb << endl;

	}
	system("pause");
	return 0;

}