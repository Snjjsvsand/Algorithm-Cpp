#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
// 模拟call ret指令
int stack[100010], top, address, n, m;
vector<int> chosen;

void call(int params , int ret_addr , int target) { // ret_addr: 函数后面下一条应该运行的指令
	int old_top = top;
	stack[++top] = params;
	stack[++top] = ret_addr;
	stack[++top] = old_top;
	address = target;
}

int ret() {
	int ret_addr = stack[top - 1];
	top = stack[top];
	return ret_addr;
}

int main() {
	cin >> n >> m;
	call(1, 0, 0);
	while ( top ) {
		int x = stack[top - 2];
		switch ( address ) {
			case 0:
				if (chosen.size() > m || chosen.size() + n - x + 1 < m) {
					address = ret();
					continue;
				}
				if (x == n + 1) {
					for (int i = 0;i < m;i++) cout << chosen[i] << ' ';
					cout << endl;
					address = ret();
					continue;
				}
				chosen.push_back(x);
				call(x + 1, 1, 0);
				continue;
			case 1:
				chosen.pop_back();
				call(x + 1, 2, 0);
				continue;
			case 2:
				address = ret();
		}
	}
	return 0;
}