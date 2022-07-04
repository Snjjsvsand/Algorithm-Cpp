#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
// 组合式枚举
const int N = 35;
int x, y, z, price[N];
vector<int> chosen;
bool happy = false;

void dfs(int u) {
    if (chosen.size() > z || chosen.size() + y - u + 1 < z) return;
    if (u == y + 1) {
        long long sum = 0;
        for (int i = 0; i < chosen.size(); i++) sum += price[chosen[i]];
        if (sum == x) happy = true;
        return;
    }

    dfs(u + 1);

    chosen.push_back(u);
    dfs(u + 1);
    chosen.pop_back();
}

int main() {
    cin >> x >> y >> z;
    for (int i = 1;i <= y;i++) cin >> price[i];
    dfs(1);
    if (happy) cout << "Happy Euphoria" << endl;
    else cout << "Happy Bu Neng" << endl;
    return 0;
}