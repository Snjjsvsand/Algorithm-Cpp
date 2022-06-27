//纯手写模拟小根堆 , 反而不如priority_queue快
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1.5e5 + 10;
int n, m, a, b, c, edge[N], ne[N], e[N], w[N] , idx , d[N] , h_size;
pair<int , int> h[N]; //堆模拟
bool st[N];

void add(int a, int b , int c) {
	e[++idx] = b;
	w[idx] = c;
	ne[idx] = edge[a];
	edge[a] = idx;
}

void swap(int a , int b) {
	pair<int , int> t = h[a];
	h[a] = h[b];
	h[b] = t;
}
	
void down(int i) {
	int t = i;
	if (i * 2 <= h_size && h[i * 2].second <= h[t].second) t = i * 2;
	if (i * 2 + 1 <= h_size && h[i * 2 + 1].second <= h[t].second) t = i * 2 + 1;
	if (t != i) swap(i, t), down(t);
}

void up(int i) {
	if (i / 2 && h[i / 2].second > h[i].second) swap(i, i / 2), up(i / 2);
}

void insert_heap(pair<int, int> i) {
	h[++h_size] = i;
	up(h_size);
}

void pop_heap() {
	h[1] = h[h_size];
	h_size--;
	down(1);
}

void dijkstra() {
	d[1] = 0;
	insert_heap({ 1 , 0 }); // index , distance

	while (h_size) {
		pair<int, int> minimum = h[1];
		pop_heap();
		int index = minimum.first, distance = minimum.second;
		//在这里判断直接退出而不是不让入堆会快一些？？？
		if (st[index]) continue;
		st[index] = true;

		for (int i = edge[index]; i ;i = ne[i]) {
			if ( d[e[i]] > distance + w[i]) {
				d[e[i]] = distance + w[i];
				insert_heap({ e[i] , d[e[i]] });
				//cout << "[" << e[i] << "," << d[e[i]] << "]" << endl;
			}
		}
	}
}



int main() {
	memset(d, 0x3f, sizeof d);
	cin >> n >> m;
	while ( m-- ) {
		cin >> a >> b >> c;
		add(a, b, c);
	}

	dijkstra();

	if (d[n] == 0x3f3f3f3f) cout << -1 << endl;
	else cout << d[n] << endl;

	return 0;
}