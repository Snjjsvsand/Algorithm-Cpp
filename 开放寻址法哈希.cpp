#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 2e5 + 3, null = 0x3f3f3f3f; //int型四个字节
int h[N] , x , n;
char c;

int find(int x) {
	int t = (x % N + N) % N;
	while (h[t] != x && h[t] != null) t = (t + 1) % N;
	return t;
}

int main() {
	memset(h, 0x3f , sizeof(h)); //按字节赋值
	cin >> n;
	while ( n-- ) {
		cin >> c >> x;
		if (c == 'I') h[find(x)] = x;
		else if(c == 'Q') cout << (h[find(x)] == null ? "Yes" : "No") << endl;
	}

	return 0;
}