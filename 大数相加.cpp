#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> add(vector<int>& a , vector<int>& b) {
	vector<int> c;
	int t = 0;
	for (int i = 0;i < a.size() || i < b.size();i++) {
		if (i < a.size()) t += a[i];
		if (i < b.size()) t += b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if (t) c.push_back(t);
	return c;
}

int main() {
	string a, b;
	vector<int> va, vb;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) va.push_back(a[i] - '0');
	for (int i = b.size() - 1;i >= 0;i--) vb.push_back(b[i] - '0');

	vector<int>vc = add(va, vb);

	for (int i = vc.size() - 1;i >= 0;i--) cout << vc[i];

	return 0;
}