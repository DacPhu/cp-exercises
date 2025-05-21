#include <bits/stdc++.h>
using namespace std;
#define fast                                                                   \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define int long long
const int maxn = 1e6 + 2;
int n, a[maxn][3], dp[maxn][3], MAX = -1e9;
signed main() {
    fast;
    cin >> n;
    fr(i, 1, n) {
        cin >> a[i][1] >> a[i][2];
        MAX = max({MAX, a[i][1], a[i][2]});
    }
    fr(i, 1, n) {
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + a[i][1]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + a[i][2]);
    }

    int ans = max(dp[n][1], dp[n][2]);
    if (!ans)
        ans = MAX;
    cout << ans;
}