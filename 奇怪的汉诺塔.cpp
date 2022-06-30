#include<iostream>
#include<cstdio>
using namespace std;
// 递推 DP
const int N = 15;
int n;
int dp[5][N]; // 0行废弃不用
// 汉诺塔算步数的核心关键在于递推式
int main() {
	cin >> n;
	dp[3][1] = 1;
	dp[4][1] = 1;
	for (int i = 2; i <= n; i++) dp[3][i] = 2 * dp[3][i - 1] + 1 , dp[4][i] = 0x3f3f3f3f;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[4][i] = min(dp[4][i] , 2 * dp[4][j] + dp[3][i - j]);
		}
	}
	cout << dp[4][n] << endl;
	return 0;
}