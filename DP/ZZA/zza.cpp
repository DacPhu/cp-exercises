#include <iostream>
#include <algorithm>

#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)
#define int long long

using namespace std;
 
const int N = 5e3 + 5;
 
int a[N], f[N][N] = {0};
 
int32_t main(){
    faster;
    int n, k, x;
    cin >> n >> k >> x;
 
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    
    //goi f[i][j] là số sinh viên ít nhất từ 1 - i với j team
 
    int pos = 0, res = 0;
    for (int i = 1; i <= n; i++){
        pos = lower_bound(a + 1, a + i + 1, a[i] - x) - a;
        for (int j = 1; j <= k; j++)
            f[i][j] = max(f[i - 1][j], f[pos - 1][j - 1] + i - pos + 1); 
        res = max(res, f[i][k]);
    }
 
    cout << res;
 
    return 0;
}