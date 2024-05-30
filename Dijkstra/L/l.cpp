#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
 
#define fi first
#define se second
#define inf 1e9 + 7

typedef pair<int,pair<double,int>> pii;
 
struct cmp {
	bool operator () (pii a,pii b) {
		return a.se.fi > b.se.fi;
	}
};
 
const int N = 1e5;
vector<pair<int,double>>a[N + 10];
double dist[N + 10][20];
int n,m,k;
 
void dijkstra(int s) {
	priority_queue<pii,vector<pii>,cmp>q;
	q.push({s,{0,0}});
	dist[s][0] = 0;
	while (!q.empty()) {
		int u = q.top().fi,tmp = q.top().se.se;
		double c = q.top().se.fi;
		q.pop();
		if (u == n) return;
		if (c > dist[u][tmp]) continue;
		for (auto x: a[u]) {
			int v = x.fi;
			double w = x.se;
			for (int i = tmp; i <= k; i++) {
				double s = c + w / pow(2,i - tmp);
				if (dist[v][i] > s) {
					dist[v][i] = s;
					q.push({v,{dist[v][i],i}});
				}
			}
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u,v;
		double w;
		cin >> u >> v >> w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++) dist[i][j] = inf;
	dijkstra(1);
	cout << fixed << setprecision(2) << dist[n][k] << "\n";
}