#include <iostream>

#define int long long
#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, f[N], pre[N];

int32_t main() {
    faster;
    cin >> n;
    f[0] = 1;
    f[1] = 2;
    f[2] = 7;
    pre[0] = 1;
    pre[1] = 3;
    pre[2] = 10;
    for (int i = 3; i <= n; i++) {
        f[i] = (f[i - 1] * 2 + f[i - 2] * 3 + pre[i - 3] * 2) % MOD;
        pre[i] = pre[i - 1] + f[i];
    }
    cout << f[n];
}