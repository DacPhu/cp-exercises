#include <iostream>
#include <string>

#define int long long
#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;

int n;
int dp[N][N];
string s, t;

int32_t main() {
    faster;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i)
        t = t + s[i];

    s = " " + s;
    t = " " + t;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (s[i] != t[j]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            } else
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    cout << n - dp[n][n];
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define fast                                                                   \
    ios_base::sync_with_stdio(0);                                              \
    cout.tie(0);                                                               \
    cin.tie(0);
const int maxn = 5e2 + 1;
string a;
int dp[maxn][maxn];
signed main() {
    fast;
    cin >> a;
    fr(i, 0, a.size() - 1) dp[i][i] = 1;
    fr(j, 0, a.size() - 1) for (int i = j; i >= 0; i--) {
        if (a[i] == a[j])
            dp[i][j] = dp[i + 1][j - 1];
        else
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
    }
    cout << dp[0][a.size() - 1];
}