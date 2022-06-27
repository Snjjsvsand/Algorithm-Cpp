#include<cstdio>
#include<iostream>
#include<unordered_map>
const int N = 400000;
using namespace std;
string res = "12345678x";
string str;
string q[N];
int h, t = -1;
int dx[] = { -1 , 0 , 1 , 0 }, dy[] = { 0 , 1 , 0 , -1 };
//unordered_map 要比 map 快好多（查找，索引）
unordered_map<string, int> d; //记录每个状态到达所需最小距离，没有就是从来没到达过

int bfs() {
	q[++t] = str;
	d.insert({ str , 0 });
	while (h <= t) {
		string state = q[h++];
		int pos = state.find('x');
		int x = pos / 3, y = pos % 3;

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string nstate = state;
				nstate[pos] = nstate[nx * 3 + ny];
				nstate[nx * 3 + ny] = 'x';

				if (!d.count(nstate)) {
					//cout << nstate << endl;
					d.insert({ nstate , d[state] + 1 });
					if (nstate == res) return d[nstate];
					q[++t] = nstate;
				}
			}
		}
	}
	return -1;
}


int main() {
	char t;
	for (int i = 0;i < 9;i++) cin >> t, str += t;
	cout << bfs() << endl;
	return 0;
}