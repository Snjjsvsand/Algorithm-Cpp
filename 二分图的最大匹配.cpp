#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 510, M = 1e5 + 10;
int n1, n2, m, edges[N], e[M], ne[M], idx , a , b , res , match[N]; //match : idx:Ů����ţ�value:��Ů��ƥ����������
bool st[N]; //st������ʶ��ÿ��ΪiѰ��ƥ���Ů��ʱ����ƥ��Ĺ����У���¼N��Ů�������ƥ��ʱ�Ƿ�ѡ��

void add(int a , int b) {
	e[++idx] = b;
	ne[idx] = edges[a];
	edges[a] = idx;
}

bool find(int x) {
	for (int i = edges[x]; i ; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {//���Ů����û�б�ѡ�У��������Ҫ�����������Ů����ʱ��������Ǳ�ѡ���ˣ�
			st[j] = true;
			if (!match[j] || find(match[j])) { //������Ů��û��ƥ����������Ů��ƥ�����������������Ů������ƥ��
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
		memset(st , 0 , sizeof st); // ��ֹÿһ��ƥ��ʱ�ظ��ı���(Ů��)
		if (find(i)) res++;
	}

	cout << res << endl;

	return 0;
}