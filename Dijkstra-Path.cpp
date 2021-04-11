#include <bits/stdc++.h>
using namespace std;
template<class T>bool chmin(T& a, const T& b) { if (b<a) { a=b; return 1;} return 0;}

const long long INF = 1LL << 60;
struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;
vector<int> pre;

vector<long long> Dijkstra(Graph &G, int s) {
    vector<long long> dist(G.size(), INF);
    dist[s] = 0;
    pre.assign(G.size(), -1);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
    que.push({dist[s], s});

    while(que.size()) {
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push({dist[e.to], e.to});
                pre[e.to] = v;
            }
        }
    }
    return dist;
}

vector<int> get_path(int t) {
    vector<int> path;
    for (; t != -1; t = pre[t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path;
}