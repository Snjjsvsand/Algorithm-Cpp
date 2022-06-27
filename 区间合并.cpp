#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> a;
int n , l , r;

int& max(int& a , int& b) {
	return a > b ? a : b;
}

void merge() {
	vector<pair<int, int>> res;
	int st = -2e9, ed = -2e9;
	for (int i = 0;i < a.size();i++) {
		if (a[i].first > ed) {
			if (st != -2e9) res.push_back({st , ed});
			st = a[i].first, ed = a[i].second;
		}
		else {
			ed = max(ed, a[i].second);
		}
	}

	if (st != -2e9) res.push_back({st , ed});

	a = res;
}

int main() {
	cin >> n;
	while (n--) cin >> l >> r, a.push_back({l , r});
	
	sort(a.begin(), a.end());
	a.erase(unique(a.begin() , a.end()) , a.end());

	merge();

	cout << a.size() << endl;

	return 0;
}