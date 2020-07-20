//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1051

using namespace std;
#include<iostream>
#include<string>
#include<vector>

void multiplier(string x, string y)
{
	if (x == "0" || y == "0")
	{
		cout << 0 << endl;
		return;
	}
	vector<int>vec(x.length()+y.length(),0);
	for (int i = y.length() - 1;i >= 0;i--)
	{
		for (int j = x.length() - 1;j >= 0;j--)
		{
			vec[i + j + 1] =vec[i+j+1]+(y[i] - '0') * (x[j] - '0');
		}
	}
	for (int i = vec.size()- 1;i > 0;i--)
	{
		if (vec[i] >= 10)
		{
			vec[i - 1] = vec[i - 1] + vec[i] / 10;
			vec[i] = vec[i] % 10;
		}
	}
	int start = 0;
	for (int i = 0;i < vec.size();i++)
	{
		if (vec[i] != 0)
		{
			start = i;
			break;
		}
	}
		for (int i = start;i < vec.size();i++)
		{
			cout << vec[i];
		}
	cout << endl;
}


int main()
{
	string x;
	string y;
	int i = 0;
	//cin >> x;
	//cin >> y;
	string temp;
	///string str;
	///cin >> temp;
	//cin >> str;
	//multiplier(x, y);
	//multiplier(temp, str);
	while (cin>>x)
	{
		cin >> y;
		multiplier(x, y);
		/*i++;
		if (i % 2==0)
		{
			x = temp;
			multiplier(x,y);
		}
		else
			y = temp;*/
	}
	system("pause");
	return 0;
}