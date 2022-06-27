#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1.5e5 + 10;
int n , m , d[N] , edge[N] , ne[N] , e[N] , w[N] , idx , a , b , c;
bool st[N];
typedef pair<int, int> PII;

void add(int a, int b , int c) {
	e[++idx] = b;
	w[idx] = c;
	ne[idx] = edge[a];
	edge[a] = idx;
}

void dijkstra() {
	d[1] = 0;
	//小根堆 <类型 ， 容器 ， 比较方式[greater , less]>
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	//pair的比较，先比较第一个元素，第一个相等比较第二个 !!!
	heap.push({ 0 , 1 }); //distance , index 
	while (heap.size()) {
		PII minimum = heap.top();
		heap.pop();
		int index = minimum.second, distance = minimum.first;
		if (st[index]) continue;
		st[index] = true;

		for (int i = edge[index]; i ; i = ne[i]) {
			if (distance + w[i] < d[e[i]]) {
				d[e[i]] = distance + w[i];
				heap.push({d[e[i]] , e[i]});
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