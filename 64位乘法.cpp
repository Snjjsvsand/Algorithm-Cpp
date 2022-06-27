#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;


LL multi64(LL a, LL b, LL p) {
    LL res = 0;
    while (b) {
        if (b & 1) res = (res + a) % p;
        b >>= 1;
        a = (2 * a) % p;
    }
    return res;
}

int main() {
    LL a, b, p;
    cin >> a >> b >> p;
    cout << multi64(a, b, p) << endl;

    return 0;
}