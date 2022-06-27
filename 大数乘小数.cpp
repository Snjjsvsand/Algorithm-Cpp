#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> mul(vector<int>& a , int b) {
	vector<int> c;
	int t = 0;
	for (int i = 0; i < a.size(); i++) {
		t += a[i] * b;
		c.push_back(t%10);
		t /= 10;
	}
	while (t) {
		c.push_back(t % 10);
		t /= 10;	
	}
	return c;
}


int main() {
	string a;
	int b;
	vector<int> A;
	cin >> a >> b;
	for (int i = a.size() - 1;i >= 0;i--) A.push_back(a[i]-'0');

	vector<int> C = mul(A, b);

	for (int i = C.size()-1;i >= 0;i--) cout << C[i];
	return 0;
}