#include <iostream>
 
#define faster ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;
 
const int inf = 1e18;
const int N = 1e4 + 4;
 
int n, c, h[N], Min;
int dp[N][1003], Minu[1003], Mind[1003];
 
void in(){
    faster;
    cin >> n >> c;

    for(int i = 1; i <= n; ++i) cin >> h[i];
 
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= 1001; ++j)
            dp[i][j] = inf;
 
    Minu[0] = Mind[1001] = inf;
}
 
void getfirst(){
    for(int j = h[1]; j <= 1000; ++j)
        dp[1][j] = (j - h[1]) * (j - h[1]);
    for(int j = 1; j <= 1000; ++j)
        Minu[j] = min(Minu[j - 1], dp[1][j] - c * j);
    for(int j = 1000; j >= 1; --j)
        Mind[j] = min(Mind[j + 1], dp[1][j] + c * j);
}
 
void DP(){
    for(int i = 2; i <= n; ++i){
        for(int j = h[i]; j <= 1000; ++j)
            dp[i][j] = min(Minu[j] + c * j, Mind[j] - c * j) + (j - h[i]) * (j - h[i]);
        for(int j = 1; j <= 1000; ++j)
            Minu[j] = min(Minu[j - 1], dp[i][j] - c * j);
        for(int j = 1000; j >= 1; --j)
            Mind[j] = min(Mind[j + 1], dp[i][j] + c * j);
    }
 
    Min = inf;
    for(int i = h[n]; i <= 1000; ++i)
        Min = min(Min, dp[n][i]);
}
 
int main(){
    in();
    getfirst();
    DP();
 
    cout << Min;
    return 0;
}