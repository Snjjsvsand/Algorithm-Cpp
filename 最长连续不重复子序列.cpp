#include<cstdio>
#include<iostream>
using namespace std;
const int N = 100010;
int n, res, a[N], s[N]; // s[N] ������¼a[i]���ֵĴ���

int max(int a , int b) {
	return a >= b ? a : b;
}
/*
	1.��ʼ[0-0]��Ȼ���������ظ�����
	2.iָ����ǰ�ߣ���������ظ�����Ȼ��a[i]�ظ�����ʱj��ǰ��ֱ����a[i]��ͬ��Ԫ���߹�
	3.ÿ��a[i]���ظ����Ա�һ�³��ȣ�������ľ��Ǵ�
*/
//j������� �� ʱ�临�Ӷ�ΪO(n) (j�����n�Σ�����i��һ��j����n��)
//˫ָ���㷨 �� aָ�������bָ����е����� j = f(i) ����
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int i = 0, j = 0;i < n;i++) {
		s[a[i]]++;
		while (j<i && s[a[i]] > 1) s[a[j]]-- , j++;
		res = max(res, i - j + 1);
	}	

	cout << res << endl;

	return 0;
}