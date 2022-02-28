#include<iostream>
#include<string>

using namespace std;

int main() {
	string str,song;
	cin >> str;
	while (!str.empty()) {
		int idx = str.find("WUB");
		if (idx == 0) {
			str.erase(0, 3);
		}
		else if(idx!=-1) {
			song += str.substr(0,idx) + " ";
			str.erase(0, idx+3);
		}
		else {
			song += str;
			break;
		}
	}
	cout << song;
	return 0;
}
