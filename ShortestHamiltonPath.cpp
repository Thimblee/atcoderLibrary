#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template<class T>bool chmin(T& a, const T& b) { if (b<a) { a=b; return 1;} return 0;}
const long long INF = 1 << 60;

int main() {
    int V, E; cin >> V >> E;
    vector<vector<long long>> edges(V, vector<long long>(V, INF));
    for (int i = 0; i < E; ++i) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
    }

    vector<vector<long long>> dp(1<<V, vector<long long>(V, INF));
    for (int i = 0; i < V; ++i) dp[1<<i][i] = 0;

    for (int bit = 1; bit < 1<<V; ++bit) {
        for (int i = 0; i < V; ++i) {
            if (bit & 1<<i) {
                const int bit2 = bit ^ 1<<i;
                for (int j = 0; j < V; ++j) {
                    if (bit2 & 1<<j) {
                        chmin(dp[bit][i], dp[bit2][j] + edges[i][j]);
                    }
                }
            }
        }
    }

    long long ans = *min_element(dp.back().begin(), dp.back().end());
    if (ans == INF) ans = -1;
    cout << ans << endl;
}