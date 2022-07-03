#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
//差分思想， 前缀和
int d[5010];
int N, P, H, M;
int a, b;
map<pair<int, int>, bool> existed;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    cin >> N >> P >> H >> M;
    while (M--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        pair<int, int> p = make_pair(a, b);
        if (existed[p]) continue;
        d[a + 1]--;
        d[b]++;
        existed[p] = true;
    }

    for (int i = 1; i <= N; i++) {
        d[i] = d[i - 1] + d[i];
        cout << d[i] + H << endl;
    }
    return 0;
}