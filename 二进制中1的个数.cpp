#include<cstdio>
#include<iostream>
using namespace std;
const int N = 100010;
int n;
int a[N];

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int i = 0;i < n;i++) {
		int t = 0;
		while (a[i]) a[i] -= (a[i] & (~a[i] + 1)) , t++;
		cout << t << ' ';
	}

}