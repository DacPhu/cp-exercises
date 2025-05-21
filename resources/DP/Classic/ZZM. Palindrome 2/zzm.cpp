#include <iostream>
#include <string>
#include <vector>

#define int long long
#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

const int INF = 1e18;

signed main() {
    faster;
    int n, k;
    string s;
    cin >> k >> s;
    n = s.size();
    s = '&' + s;
    vector<vector<int>> c(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; ++i) {
        c[i][i] = 0;
        if (i < n) {
            c[i][i + 1] = s[i] == s[i + 1] ? 0 : 1;
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = i + 2; j <= n; ++j) {
            c[i][j] = c[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 0; l < i; ++l) {
                if (dp[l][j - 1] != 1e9) {
                    dp[i][j] = min(dp[i][j], dp[l][j - 1] + c[l + 1][i]);
                }
            }
        }
    }
    cout << dp[n][k];
}