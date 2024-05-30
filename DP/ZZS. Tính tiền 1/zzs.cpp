#include <iostream>
 
using namespace std;
 
#define fastio              ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
#define file1(task1)        if(fopen(task1".inp", "r")) {freopen(task1".inp", "r", stdin); freopen(task1".out", "w", stdout);}
#define file2(task2)        if(fopen(task2".inp", "r")) {freopen(task2".inp", "r", stdin);}
 
#define int                 long long
 
#define fou(i,a,b)          for (int i = a; i <= b; i++)
#define fod(i,a,b)          for (int i = a; i >= b; i--)
 
#define fi                  first
#define se                  second
#define pb                  push_back
 
#define endl                "\n"
 
#define round_up(a)         ceil ((double) a)
#define round_down(a)       floor((double) a)
 
#define oo                  1000000000000000005
#define N                   1000005
 
#define block_size          505
#define B(x)                round_up(x/block_size)
 
int n;
int t[N], c[N];
int dp[N];
 
signed main() {
    fastio;
 
    file1("");
    file2("");
 
    cin >> n;
    fou(i,1,n) cin >> t[i] >> c[i], t[i]++;
    fill(dp,dp+N,oo); dp[0] = 0;
    int ans = oo;
    for (int i = 1; i <= n; ++i){
        for (int j = n + 2000; j >= t[i]; --j){
            dp[j] = min(dp[j], dp[j - t[i]] + c[i]);
            if (j >= n) ans = min(ans, dp[j]);
        }
    }
    cout << ans;
    return 0;
}