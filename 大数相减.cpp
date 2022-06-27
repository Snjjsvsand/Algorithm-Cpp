#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool cmp(vector<int>& a , vector<int>& b) {
	if (a.size() != b.size()) return a.size() >= b.size();
	for (int i = a.size()-1 ; i >= 0 ; i--) {
		if (a[i] != b[i]) return a[i] > b[i];
	}
	return true;
}

vector<int> sub(vector<int>& a , vector<int>& b) {
	vector<int> c;
	for (int i = 0 , t = 0;i < a.size();i++) {
		//t 用来记录 借位 (兼具计算当前位数的得数((t+10)%10))
		t = a[i] - t;
		if (i < b.size()) t -= b[i];
		c.push_back((t+10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}
	while (c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}

int main() {
	string a, b;
	vector<int> va, vb , c;
	cin >> a >> b;
	for (int i = a.size() - 1;i >= 0;i--) va.push_back(a[i] - '0');
	for (int i = b.size() - 1;i >= 0;i--) vb.push_back(b[i] - '0');

	if (cmp(va, vb)) {
		c = sub(va, vb);
	}else {
		c = sub(vb, va);
		cout << '-';
	}

	for (int i = c.size() - 1;i >= 0;i--) cout << c[i];

	return 0;
}
