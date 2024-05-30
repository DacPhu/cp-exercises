#include <iostream>

#define int long long
#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;
 
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
 
int n, m, a[N], res, dp[N][3], f[N][3];
 
int32_t main() {
    faster;
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    f[1][0] = 1;
    f[1][2] = 1;
    for(int i = 2; i <= n; i++) {
        f[i][0] = (f[i -1][0] + f[i - 1][2]) % MOD;
        f[i][2] = f[i-1][0];
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (f[i - 1][0] + f[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
    return 0;
}