#include <iostream>

#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)
#define int long long

using namespace std;

const int N = 1e6 + 3;
const int MOD = 998244353;

int f[N + 3], sum[N + 3];

int32_t main(){
    faster;
    int n; cin >> n;
    f[0] = 1;
    f[1] = 1;
    f[2] = 5;
    sum[1] = 0;
    sum[2] = 12;
    for(int i = 3; i <= n; i++){
        f[i] = (f[i - 1] + 4 * f[i - 2] + 2 * f[i - 3]) % MOD;
        sum[i] = (sum[i - 1] + 4 * sum[i - 2] + 2 * sum[i - 3] + 12 * f[i - 2] + 12 * f[i - 3]) % MOD;
    }
    cout << sum[n] << '\n';
    return 0;
}