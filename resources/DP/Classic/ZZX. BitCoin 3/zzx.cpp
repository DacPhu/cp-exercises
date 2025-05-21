#include <iostream>

using namespace std;
#define int long long
#define fast                                                                   \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(NULL);                                                             \
    cout.tie(0);
const int N = 1e6 + 2;
int n, k, a[N], dp[N];
signed main() {
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = n; i > 0; --i)
        a[i] = a[i] - a[i - 1];
    for (int i = 1; i <= k; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp[j] = max(dp[j - 1] + a[j], dp[j]);
        }
        for (int j = 3; j <= n; ++j)
            dp[j] = max(dp[j - 1], dp[j]);
    }
    cout << (dp[n] < 0 ? 0 : dp[n]);
}