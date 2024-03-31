#include <iostream>

#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;
 
#define int long long

int n , m;
const int N = 1505;
int a[N][N], dp[2][N],l[N],r[N];
 
int32_t main(){
	faster;
	cin >> n >> m;
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= m;j++){
			cin >> a[i][j];
		}
	}
	int ans = 1e18;
	for(int i = 1; i <= n;i++){
		// li = min 1-> i , ri = min i -> n
		for(int j = 0; j <= m+1;j++){
			l[j] = 1e18;
			r[j] = 1e18;
		}
		for(int j = 1; j <= m;j++){
			l[j] = min(dp[(i-1)%2][j],l[j-1]);
		}
		for(int j = m; j >= 1;j--){
			r[j] = min(dp[(i-1)%2][j],r[j+1]);
		}
		for(int j = 1; j <= m;j++){
			dp[i%2][j] = min(l[j-1],r[j+1]) + a[i][j];
		}
	}
	for(int i = 1; i <= m;i++){
		//cout << dp[n][i] << " ";
		ans = min(ans,dp[n%2][i]);
	}
	cout << ans;
}
