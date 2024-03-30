#include <iostream>
#include <queue>

#define int long long
#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)

using namespace std;
 
const int N = 1e6 + 15;
const int MOD = 1e9 + 7;
 
int n, m, a[N], res, dp[N], k;
deque<int> dq;
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        while(dq.size() && a[dq.back()] >= a[i]) 
            dq.pop_back();
        dq.push_back(i);
        if(dq.front() + k <= i)
            dq.pop_front();
        if(i >= k) {
            dp[i] = max(dp[i - 1],dp[i - k] + a[dq.front()]);
        }
    }
    cout << dp[n];
    return 0;
}