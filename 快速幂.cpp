#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1e5 + 10;
int n;
long long a, b, p;

long long qmi(int a, int k, int p) {
    long long res = 1;
    while (k) {
        if (k & 1) res = (long long)res * a % p;
        k >>= 1;
        a = (long long)a * a % p;
    }

    return res;
}

int main() {
    cin >> n;
    while (n--) {
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }

    return 0;
}