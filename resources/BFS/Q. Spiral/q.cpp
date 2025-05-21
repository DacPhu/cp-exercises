#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define fi first
#define se second
const int N = 1e3;
int a[N + 10][N + 10], n, dist[N + 10][N + 10];
bool isVisited[N + 10][N + 10];
int moveX[] = {-1, 0, 0, 1};
int moveY[] = {0, -1, 1, 0};

void init(int n) {
    int cnt = 0, v = 1, r = n, c = n;
    while (cnt < n * n) {
        for (int i = v; i <= c; i++) {
            cnt++;
            a[v][i] = cnt;
        }
        for (int i = v + 1; i <= r; i++) {
            cnt++;
            a[i][c] = cnt;
        }
        for (int i = c - 1; i >= v; i--) {
            cnt++;
            a[r][i] = cnt;
        }
        for (int i = r - 1; i > v; i--) {
            cnt++;
            a[i][v] = cnt;
        }
        v++, r--, c--;
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    isVisited[x][y] = true;
    dist[x][y] = 0;
    while (!q.empty()) {
        int ux = q.front().fi, uy = q.front().se;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int vx = ux + moveX[i], vy = uy + moveY[i];
            if (1 <= vx && vx <= n && 1 <= vy && vy <= n &&
                !isVisited[vx][vy] && __gcd(a[ux][uy], a[vx][vy]) == 1) {
                q.push({vx, vy});
                isVisited[vx][vy] = true;
                dist[vx][vy] = dist[ux][uy] + 1;
            }
        }
    }
}

void solve() {
    memset(isVisited, false, sizeof(isVisited));
    int x, y, s, t, u, v;
    cin >> n >> x >> y;
    init(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == x)
                s = i, t = j;
            else if (a[i][j] == y)
                u = i, v = j;
    bfs(s, t);
    if (!isVisited[u][v])
        cout << -1 << "\n";
    else
        cout << dist[u][v] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}