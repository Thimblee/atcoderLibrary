#include <vector>
using namespace std;

const int maxn = 15; // change
const long long INF = 1LL << 60;
int N;
vector<vector<long long>> dist(maxn, vector<long long>(maxn, INF));
vector<vector<long long>> dp(1<<maxn, vector<long long>(maxn, -1));

long long dfs(int s, int v) {
    if (dp[s][v] >= 0) return dp[s][v];
    if (s == (1<<N)-1 && v == 0) return dp[s][v] = 0;

    long long ans = INF;
    for (int i = 0; i < N; ++i) {
        if (!(s >> i & 1)) {
            ans = min(ans, dfs(s | 1 << i, i) + dist[v][i]);
        }
    }
    dp[s][v] = ans;
    return ans;
}