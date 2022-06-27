#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 510, M = 1e5 + 10;
int n1, n2, m, edges[N], e[M], ne[M], idx , a , b , res , match[N]; //match : idx:女生编号，value:跟女生匹配的男生编号
bool st[N]; //st用来标识，每次为i寻找匹配的女生时，在匹配的过程中，记录N个女生在这次匹配时是否被选中

void add(int a , int b) {
	e[++idx] = b;
	ne[idx] = edges[a];
	edges[a] = idx;
}

bool find(int x) {
	for (int i = edges[x]; i ; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {//这个女生还没有被选中（别的男生要求这个男生换女生的时候这里就是被选中了）
			st[j] = true;
			if (!match[j] || find(match[j])) { //如果这个女生没有匹配男生或者女生匹配的男生还有其他的女生可以匹配
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n1 >> n2 >> m;
	while ( m-- ) {
		cin >> a >> b;
		add(a, b);
	}

	for (int i = 1;i <= n1;i++) {
		memset(st , 0 , sizeof st); // 防止每一次匹配时重复的遍历(女生)
		if (find(i)) res++;
	}

	cout << res << endl;

	return 0;
}