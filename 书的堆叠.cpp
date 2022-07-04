#include<iostream>
#include<cstdio>
using namespace std;
// ��N�����ų�һ�У���֪��i���ĺ����Ai�������Ƿֳ�������M�飬ʹT��С����T��ʾ���֮������һ��ĺ�ȡ�
// ����������������
const int N = 10010;
int n, m;
int a[N];
int l, r;

// ���s��һ�����н⣬����Է�M�飬��ÿһ����ĺ�ȵ�������С�ڵ���s �� ��ʱ�����Ž����ȡ[l , s] , ��֮������ȡ(s , r]
bool valid(int s) {
	int rest = s, group = 1;
	for (int i = 0;i < n; i++) {
		if (rest >= a[i]) rest -= a[i];
		else group++, rest = s - a[i];
	}
	return group <= m;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n; i++) cin >> a[i], r += a[i];
	while (l < r) {
		int mid = l + r >> 1;
		if (valid(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl; // l == r true
	return 0;
}