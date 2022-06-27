#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n, m;
int top, address;
int stack[100010];
vector<int> chosen;

void call(int u , int ret_address) {
	int old_top = top;
	stack[++top] = u;
	stack[++top] = ret_address;
	stack[++top] = old_top;
}

int ret() {
	int ret_address = stack[top - 1];
	top = stack[top];
	return ret_address;
}


int main() {
	cin >> n >> m;

	// 开始第一次递归
	call(1 , 0);
	
	while (top) {
		// 获取参数
		int u = stack[top - 2];
		switch (address) {
			case 0:
				if (chosen.size() + n - u + 1 < m || chosen.size() > m || m == 0) {
					address = ret();
					continue;
				}
				if (u > n) {
					for (int i = 0;i < chosen.size();i++) cout << chosen[i] << ' ';
					cout << endl;
					address = ret();
					continue;
				}
				chosen.push_back(u);
				call(u + 1 , 1) , address = 0;
				continue;
			case 1:
				chosen.pop_back( );
				call(u + 1 , 2) , address = 0;
				continue;
			case 2:
				address = ret();
				continue;

		}
	}

	return 0;
}