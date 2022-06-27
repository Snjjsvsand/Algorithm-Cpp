#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int N = 1e6 + 10;
int h[N] , ph[N] , hp[N] , size_h , n , idx;
string op;

void swap(int a , int b) { //heap_swap
	int t;
	t = ph[hp[a]], ph[hp[a]] = ph[hp[b]], ph[hp[b]] = t;
	t = hp[a], hp[a] = hp[b], hp[b] = t;
	t = h[a], h[a] = h[b], h[b] = t;
}

void down(int i) {
	int t = i;
	if (i * 2 <= size_h && h[i * 2] < h[t]) t = i * 2;
	if (i * 2 + 1 <= size_h && h[i * 2 + 1] < h[t]) t = i * 2 + 1;
	if (t != i) swap(t, i), down(t);
}

void up(int i) {
	while (i / 2 && h[i / 2] > h[i]) {
		swap(i / 2, i);
		i /= 2;
	}
}

int main() {
	cin >> n;
	while ( n-- ) {
		cin >> op;
		if (op == "I") {
			int x;
			cin >> x;
			h[++size_h] = x;
			ph[++idx] = size_h;
			hp[size_h] = idx;
			up(size_h);
		}
		else if (op == "PM") {
			cout << h[1] << endl;
		}
		else if (op == "DM") {
			h[1] = h[size_h], size_h--;
			down(1);
		}
		else if (op == "D") {
			int k;
			cin >> k;
			swap(ph[k] , size_h), size_h--;
			up(ph[k]) , down(ph[k]);
		}
		else if (op == "C") {
			int k, x;
			cin >> k >> x;
			h[ph[k]] = x;
			up(ph[k]), down(ph[k]);
		}
	}


	return 0;
}