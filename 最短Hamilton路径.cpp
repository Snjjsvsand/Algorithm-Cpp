#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
// ·��ѹ��&λ����
const int N = 1 << 21, M = 21;
int n, dp[N][M], g[M][M];
int main() {
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> g[i][j];
	memset(dp, 0x3f, sizeof dp);
	dp[1][0] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0;j < n;j++) {
			if (i >> j & 1) {
				for (int k = 0;k < n;k++) {
					if ((i ^ (1 << j)) >> k & 1) { // �ھ���k�ڵ����dpʱ��Ҫ��֤k�㱻�߹���j��δ���߹���״̬  n xor 1 << j : ��jλȡ��
						dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + g[k][j]);
					}
				}

			}
		}
	}
	cout << dp[(1 << n) - 1][n - 1] << endl;
	return 0;
} 