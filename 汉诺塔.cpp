#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
// 递推 / 递归
// d[i] = 2 * d[i - 1] + 1
int n;

void move(int n, char origin , char target , char support) {
	if (n == 1) {
		cout << origin << " -> " << target << endl;
		return;
	}
	move(n - 1 , origin , support , target);
	cout << origin << " -> " << target << endl;
	move(n - 1 , support , target , origin);
}

//将n个盘子从A移动到B

int main() {
	cin >> n;
	move(n , 'A' , 'B' , 'C');
	cout << pow(2, n) - 1 << endl; // 移动的次数
	return 0;
}