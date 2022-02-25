#include<iostream>
using namespace std;
#include<string>

int n, m;
string colors = "CMY";

int main() {
	cin >> n >> m;
	n *= m;
	while (n--) {
		char c;
		cin >> c;
		if (colors.find(c) != -1) {
			cout << "#Color";
			return 0;
		}
	}
	cout<< "#Black&White";
	return 0;
}
