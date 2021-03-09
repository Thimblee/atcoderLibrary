#include <bits/stdc++.h>
using namespace std;

vector<bool> seen;
vector<int> order;
void rec(vector<vector<int>> &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        rec(G, next_v);
    }
    order.push_back(v);
}

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    seen.assign(N, false);
    order.clear();
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue;
        rec(G, v);
    }
    reverse(order.begin(), order.end());
}