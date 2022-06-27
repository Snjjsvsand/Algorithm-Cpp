#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int edge[N], ne[N * 2], e[N * 2], idx, n , a , b , res = N;
bool st[N]; //st������¼����ڵ��Ƿ񱻼�¼��
//����ڵ�AҪ��ڵ�B���ӽڵ�������A��Bͨ��, B��������һ��A�ˣ����򲻽����Ի������޵ݹ�

void add(int a, int b) {
	e[++idx] = b;
	ne[idx] = edge[a];
	edge[a] = idx;
}

int dfs(int node) {
	int sum = 1, m = 0;
	st[node] = true;
	
	for (int i = edge[node]; i ; i = ne[i]) {
		if (!st[e[i]]) {
			int t = dfs(e[i]);
			m = max(m , t);
			sum += t;
		}
	}

	m = max(m , n - sum);
	res = min(res , m);
	return sum;
}

int main() {
	cin >> n;
	for (int i = 0;i < n - 1;i++) {
		cin >> a >> b;
		add(a, b), add(b, a);
	}

	dfs( 1 );
	
	cout << res << endl;
	
	return 0;
}