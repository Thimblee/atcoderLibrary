#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
template<class T>bool chmin(T& a, const T& b) { if (b<a) { a=b; return 1;} return 0;}

const ll INF = 1LL << 60;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    int N, M, s;
    cin >> N >> M >> s;

    Graph G(N);
    rep(i, M) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    bool exist_negative_cycle = false;
    vector<ll> dist(N, INF);
    dist[s] = 0;
    for (int iter = 0; iter < N; ++iter) {
        bool update = false;
        for (int v = 0; v < N; ++v) {
            if (dist[v] == INF) continue;

            for (auto e : G[v]) {
                if (chmin(dist[e.to], dist[v] + e.w)) {
                    update = true;
                }
            }
        }
        if (!update) break;
        if (iter == N - 1 && update) exist_negative_cycle = true;
    }

    if (exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int v = 0; v < N; ++v) {
            if (dist[v] < INF) cout << dist[v] << endl;
            else cout << "INF" << endl;
        }
    }
}