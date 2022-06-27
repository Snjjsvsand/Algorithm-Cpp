#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
	#include<iostream> 将文件iostream放到命名空间std中 ，using指令使该名称空间在函数中可用

*/

vector<int> div(vector<int>& a , int b , int& r) {
	vector<int> c;
	for (int i = 0;i < a.size();i++) {
		r = r * 10 + a[i];
		c.push_back(r / b);
		r %= b;
	}

	reverse(c.begin() , c.end());
	while (c.size() && c.back() == 0) c.pop_back();
	reverse(c.begin() , c.end());

	return c;
}


int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	string a;
	int b , r = 0; //b是除数 ， r是余数
	vector<int> A;
	cin >> a >> b;
	for (int i = 0;i < a.size();i++) A.push_back(a[i] - '0');

	vector<int> C = div(A , b , r);

	for (int i = 0;i < C.size();i++) cout << C[i];
	cout << endl << r;

	return 0;
}