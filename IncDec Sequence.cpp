#include<iostream>
#include<cstdio>
using namespace std;
// ���
const int N = 1e5 + 10;
int n, a[N], d[N];
long long p, q; // ��������������븺���ĸ���
// ����е�Sn+1�е�+1�ǳ���Ҫ(�����㷨��������ָ�ϡ�)
long long longAbs(long long a) {
    return a > 0 ? a : -a;
}
//a[1~n] , ��[l , r]�е�ȫ���������ӻ���٣� ���Ըı�d[n + 1]������r����n����� , �ı�d[1]������l��1С�����
int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        d[i] = i == 1 ? a[i] : a[i] - a[i - 1];
        if (i - 1 && d[i] > 0) p += d[i]; // ��d[2]��ʼ d[1] = a[1]
        if (i - 1 && d[i] < 0) q -= d[i]; // d[i]Ϊ����
    }
    for (int i = 0; i <= longAbs(p - q); i++) { // ������ܵ�ȫ����ȵ�a[i]��ֵ
        cout << d[1] + i << endl;
    }
    cout << max(p, q) << endl << longAbs(p - q) + 1 << endl;
    return 0;
}