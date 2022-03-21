// http://codeforces.com/contest/79/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
#include<map>

#include<sstream>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define sz(v)  ((int)((v).size()))
#define loop(i,st,n) for(int i=st;i<=n;i++)

string veg[] = { "Grapes","Carrots","Kiwis"};

struct cell {
	int i, j, waste;
	cell(int ci, int cj, int w) {
		waste = w;
		i = ci;
		j = cj;
	}
	// when false is returned, the upperbound shift the pointer to left
	struct greater_than {
		bool operator()(const cell& pi1, const cell& pi2) {
			if (pi1.i != pi2.i)
				return pi1.i > pi2.i;
			else
				return pi1.j >= pi2.j;
		}
	};
};

typedef vector<cell> vi;
typedef vector<cell>::iterator vecIt;

void increment(int & i,int & j,int & m) {
	j++;
	if (j > m) {
		j = 1;
		i++;
	}
}

int main() {
	int n, m, k, t, li = 1,lj = 1;
	cin >> n >> m >> k >> t;
	int w = 0;
	vi waste(k, cell(0, 0, 0));
	loop(idx,0,k-1){
		int i, j;
		cin >> i >> j;
		waste[idx].i = i;
		waste[idx].j = j;
	}
	// sort array descendingly to find greatest cell smaller or equal given one in upper_bound
	sort(all(waste), [](const cell & pi1, const cell & pi2) {
		if (pi1.i != pi2.i)
			return pi1.i > pi2.i;
		else
			return pi1.j > pi2.j;
	});
	for (int idx = k - 1; idx >= 0;idx--) {
		waste[idx].waste = ++w;
	}
	while (t--) {
		int qi, qj;
		cin >> qi >> qj;
		cell c(qi, qj, 0);
		auto it = upper_bound(all(waste),c, cell::greater_than());
		if (it == waste.end()) {
			cout << veg[((qi - 1) * m + qj)%3] << endl;
		}
		else if ( it->i == qi && it->j == qj ) {
			cout << "Waste" << endl;
		}
		else {
			cout << veg [((qi - 1) * m + qj - it->waste) % 3 ]<< endl;
		}
	}
	return 0;
}
