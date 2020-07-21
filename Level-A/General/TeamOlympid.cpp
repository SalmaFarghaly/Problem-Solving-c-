//https://codeforces.com/contest/490/problem/A

using namespace std;
#include<string>
#include<iostream>
#include<cmath>

void main()
{
	int n;
	cin >> n;
	string str;
	getline(cin,str);
	getline(cin, str);
	int k = 0;
	int TeamNum = 0;
	int Num1 = 0;
	int Num2 = 0;
	int Num3 = 0;
	for (int i = 0;i < n;i++)
	{
		if (str[k] == '1')
			Num1++;
		if (str[k] == '2')
			Num2++;
		if (str[k] == '3')
			Num3++;
		k = k+ 2;
	}
	TeamNum=fmin(Num1,fmin(Num2,Num3));
	cout << TeamNum<<endl;
	if (TeamNum == 0)
		return;
	k = 0;
	int ChildNum = -1;
	int j = 0;
	int arrTeam[3] = { 0,0,0 };
	for (int j = 0;j < TeamNum;j++)
	{
		for (int i = 0;i < n;i++)
		{
			if (str[k] == '0')
			{
				k = k + 2;
				ChildNum++;
				continue;
			}
			if (str[k] == '1')
			{
				if (arrTeam[0] == 0)
				{
					arrTeam[0] = k-ChildNum;
					str[k] = '0';
				}
			}
			if (str[k] == '2')
			{
				if (arrTeam[1] == 0)
				{
					arrTeam[1] = k-ChildNum;
					str[k] = '0';
				}
			}
			if (str[k] == '3')
			{
				if (arrTeam[2] == 0)
				{
					arrTeam[2] = k-ChildNum;
					str[k] = '0';
				}
			}
			//str[k] = '0';
			ChildNum++;
			k = k + 2;
			if (arrTeam[0] != 0 && arrTeam[1] != 0 && arrTeam[2] != 0)
			{
				string Team;
				Team = to_string(arrTeam[0]) + " " + to_string(arrTeam[1]) + " " + to_string(arrTeam[2]);
				cout << Team<<endl;
				arrTeam[1] = 0;
				arrTeam[2] = 0;
				arrTeam[0] = 0;
				k = 0;
				ChildNum = -1;
				break;
			}
		}
	}
	system("pause");
}