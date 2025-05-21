#include <iostream>
#include <string>

#define faster                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0);                                                                \
    cout.tie(0);
#define int long long

using namespace std;

const int N = 4e3 + 4;

string s;

int f[N][N], d[N];
bool check[N][N];

int32_t main() {
    faster;
    cin >> s;
    int n = s.size();
    s = '?' + s;

    for (int i = 1; i <= n; ++i)
        for (int l = 1; l <= n - i + 1; ++l) {
            int r = l + i - 1;

            if (i == 1)
                check[l][r] = true;
            else if (i == 2) {
                if (s[l] == s[r])
                    check[l][r] = true;
                else
                    check[l][r] = false;
            } else {
                if (s[l] == s[r])
                    check[l][r] = check[l + 1][r - 1];
                else
                    check[l][r] = false;
            }
        }
    for (int i = 1; i <= n; ++i)
        for (int l = 1; l <= n - i + 1; ++l) {
            int r = l + i - 1;

            if (check[l][r]) {
                if (i == 1)
                    f[l][r] = 1;
                else {
                    int m = (r + l) / 2;

                    if (i % 2 == 1)
                        f[l][r] = min(f[l][m - 1], f[m + 1][r]) + 1;
                    else
                        f[l][r] = min(f[l][m], f[m + 1][r]) + 1;
                }
            }
        }

    for (int i = 1; i <= n; ++i)
        for (int l = 1; l <= n - i + 1; ++l)
            d[f[l][l + i - 1]]++;

    for (int i = n; i >= 1; --i)
        d[i] += d[i + 1];

    for (int i = 1; i <= n; ++i)
        cout << d[i] << " ";

    return 0;
}