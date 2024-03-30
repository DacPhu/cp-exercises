#include <iostream>
using namespace std;

#define faster ios_base::sync_with_stdio(false), cin.tie(NULL)
 
const int N = 2e3 + 3;
int dp[N][N];
 
int main() {
	faster;
	string a,b = "";
	cin >> a;
	int n = a.size();
	for (int i = n - 1; i >= 0; i--) b = b + a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
	cout << dp[n][n] << "\n";
}