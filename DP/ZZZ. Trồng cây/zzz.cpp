#include <iostream>

#define int long long
#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;
 
const int N = 1e5 + 1;
const int mod = 1e9 + 7;
int n, m, a[N], b[N], cnt, v[N], w[N], res, f[1001], x[N], c[N], t, k;
 
int cal(int v,int cnt,int w){
	return v * cnt - w * (cnt * (cnt - 1)) / 2;
}
 
int32_t main() {
    faster;
    cin >> n >> m ;
    for(int i = 1; i <= n; ++i) 
        cin >> c[i] >> v[i] >> w[i];
    for(int i = 1; i <= m; ++i) {
    	cin >> b[i];
    	k = max(k, b[i]);
	 }
    for(int i = 1; i <= n; ++i)
        for(int j = k; j >= c[i]; j--)
            for (int s = 0; s <= min(j / c[i], (v[i] / w[i]) + 1); s++)
                f[j] = max(f[j], f[j - c[i] * s] + cal(v[i], s, w[i]));

    for(int i = 1; i <= m; ++i) 
        cout << f[b[i]] << " ";
}
