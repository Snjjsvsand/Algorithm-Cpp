#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10 , q = 100003;
int n, h[N], e[N], ne[N], idx , x;
char c;

void insert(int x) {
	int hash = (x % q + q) % q;
	e[++idx] = x;
	ne[idx] = h[hash];
	h[hash] = idx;
}

bool find(int x) {
	int hash = (x % q + q) % q;
	for (int i = h[hash]; i; i = ne[i]) if (e[i] == x) return true;
	return false;
}


int main() {
	cin >> n;
	while ( n-- ) {
		cin >> c >> x;
		if (c == 'I' && !find(x)) insert(x);
		else if(c == 'Q') cout << (find(x) ? "Yes" : "No") << endl;
	}
	return 0;
}