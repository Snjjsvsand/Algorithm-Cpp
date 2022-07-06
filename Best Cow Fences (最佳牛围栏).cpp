#include<iostream>
#include<cstdio>
using namespace std;
// �������� + ǰ׺��
const int N = 1e5 + 10;
int a[N];
int n, f;
double s[N], l, r;
// ƽ��ֵ���ü��ɣ�ȫ����ȥƽ��ֵ��
// ���������������������е�ǰ׺��˼�룬 ȫ����ȥƽ����֮��С��0������ͻ�Ϊ�������������
bool valid(double x) {
	double minV = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - x;
	for (int i = f; i <= n; i++) {
		minV = min(minV, s[i - f]);
		if (s[i] - minV >= 0) return true;
	}
	return false;
}

int main() {
	cin >> n >> f;
	for (int i = 1; i <= n; i++) cin >> a[i], r = max(r, (double)a[i]);
	while (r - l > 1e-5) {
		double mid = (l + r) / 2;
		if (valid(mid)) l = mid;
		else r = mid;
	}
	cout << (int)(r * 1000) << endl;
	return 0;
}