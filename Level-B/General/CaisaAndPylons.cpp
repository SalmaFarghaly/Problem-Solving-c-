// https://codeforces.com/contest/463/problem/B

using namespace std;
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>


int main() {
	int n = 0;
	cin >> n;
	int diff = 0;
	int energy = 0;
	int prev = 0;
	int next = 0;
	for (int i = 0;i < n;i++) {
		cin >> next;
		if (prev - next >= 0) {
			energy += prev - next;
		}
		else {
			if (energy >= next-prev) {
				energy -= next - prev;
			}
			else {
				diff += next - prev-energy;
				energy = 0;
			}
		}
		prev = next;
	}
	cout << diff;
	system("pause");
	return 0;
}

