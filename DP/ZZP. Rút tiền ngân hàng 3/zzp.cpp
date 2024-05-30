//|Art|
//#pragma GCC optimize("02,unroll-loops")
//#pragma GCC target("avx2,fma")
 
#include <iostream>
#include <chrono>
#include <algorithm>
//#include <bits/stdc++.h>
 
#define el cout << '\n'
#define fi first
#define se second
#define pb push_back
 
#define sz(x) (x).size()
#define all(v) (v).begin(), (v).end()
 
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define REV(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define REP(i, n) for(int i = 0, _n = (n); i < _n; ++i)
 
#define __Art__ signed main()
#define name "Art"
const int maxN = 1e5 + 10;
 
using namespace std;
 
int n, T;
long long dp[maxN][105];
int res;
 
struct node {
    int a, t, p;
} Q[maxN];
 
bool cmp(node a, node b) {
    if (a.t == b.t) return a.p < b.p;
    return a.t < b.t;
}
 
void input() {
    cin >> n >> T;
    FOR (i, 1, n) {
        cin >> Q[i].a >> Q[i].t >> Q[i].p;
    }
}
 
namespace solution {
    bool check_sub() {
        return true;
    }
 
    void solve() {
        sort (Q + 1, Q + n + 1, cmp);
 
        FOR (i, 1, n) FOR (j, 1, T + 1) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            
            if (j >= Q[i].p && Q[i].t + 1 >= j) 
                dp[i][j] = max(dp[i][j], dp[i - 1][j - Q[i].p] + Q[i].a);
        }
 
        cout << dp[n][T + 1];
    }
 
    void time() {
        cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    }
}
 
__Art__ {
 
    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
 
    input();
    if (solution::check_sub()) {
        solution::solve();
        solution::time();
        return 0;
    }
 
    return (1 ^ 1);
}