#include<iostream>
#include<cstring>
using namespace std;
const int N = 400000 + 9;
typedef char state[9]; // 定义state为8个char元素的数组类型
state firstState, q[N], res = {'1','2','3','4','5','6','7','8','x'};
int h, t = -1 , dx[] = { -1 , 0 , 1 , 0 }, dy[] = {0 , 1 , 0 , -1};
int linkHash[N], ne[N], e[N] , idx , d[N];


int getPrimeNumber() {
	for (int i = N ; ; i++) {
		int flag = 1;
		for (int j = 2;j * j <= i;j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) return i;
	}
}

void insert(int x) {
	int k = (x % N + N) % N;
	e[++idx] = x;
	ne[idx] = linkHash[k];
	linkHash[k] = idx;
}

int find(int x) {
	int k = (x % N + N) % N;
	for (int i = linkHash[k]; i ; i = ne[i]) {
		if (e[i] == x) return i;
	}
	return 0;
}

int mapState2Int(state& s) {
	int res = 0;
	for (int i = 0;i < 9;i++) {
		int t;
		t = s[i] == 'x' ? 0 : s[i] - '0';
		res = res * 10 + t;
	}
	return res;
}

void addQueue(state& s) {
	++t;
	for (int i = 0;i < 9;i++) q[t][i] = s[i];
}

void deleteQueue(state& st) {
	for (int i = 0;i < 9;i++) st[i] = q[h][i];
	h++;
}


int bfs() {
	addQueue(firstState);
	insert(mapState2Int(firstState));
	d[find(mapState2Int(firstState))] = 0;

	while ( h <= t ) {
		state st , nst;
		deleteQueue(st);
		
		int pos , x , y , nx , ny;
		for (int i = 0;i < 9;i++) if (st[i] == 'x') pos = i;
		x = pos / 3, y = pos % 3;
		
		for (int i = 0;i < 4;i++) {
			nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				for (int i = 0;i < 9;i++) nst[i] = st[i];
				nst[pos] = nst[nx * 3 + ny];
				nst[nx * 3 + ny] = 'x';
				if (!find(mapState2Int(nst))) {
					insert(mapState2Int(nst));
					//for (int i = 0;i < 9;i++) cout << nst[i] << ' ';
					//cout << endl;

					d[find(mapState2Int(nst))] = d[find(mapState2Int(st))] + 1;
					
					bool flag = true;
					for (int i = 0;i < 9;i++) if (nst[i] != res[i]) flag = false;
					if (flag) return d[find(mapState2Int(nst))];

					addQueue(nst);
				}
			}
		
		}
		
	}
	return -1;
}



int main() {
	memset(d, -1, sizeof d);
	for (int i = 0;i < 9;i++) cin >> firstState[i];
	cout << bfs() << endl;
	return 0;
}