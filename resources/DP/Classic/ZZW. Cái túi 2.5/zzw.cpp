#include <iostream>

#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)
#define int long long

using namespace std;

const int N = 1e6 + 6;
int n, s, sl, a[N], w[N], v[N], f[N];

int32_t main() {
    faster;
    cin >> n >> s;

    for (int i = 1; i <= n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        for (int j = 1; j <= z; j = j * 2) {
            if (z >= j) {
                sl++;
                z -= j;
                w[sl] = j * x;
                v[sl] = j * y;
            }
        }
        if (z > 0) {
            sl++;
            w[sl] = z * x;
            v[sl] = z * y;
        }
    }

    for (int i = 1; i <= sl; ++i) {
        for (int j = s; j >= w[i]; --j) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= s; i++)
        ans = max(ans, f[i]);
    cout << ans;
    return 0;
}