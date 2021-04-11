// Reference: https://misteer.hatenablog.com/entry/persistentUF
#include <vector>
using namespace std;

const int INF = 2e9;

struct PartiallyPersistentUF {
    int now;
    vector<int> par; // Parent of each vertex
    vector<int> rank; // the depth of the tree rooted at the vertex
    vector<int> time; // the time when the parent was updated
    vector<vector<pair<int, int>>> num; // (time, number of vertices)

    PartiallyPersistentUF(int sz) : par(sz), rank(sz, 0), time(sz, INF), num(sz) {
        now = 0;
        for (int i = 0; i < sz; ++i) {
            par[i] = i;
            num[i].push_back(make_pair(0, 1));
        }
    }

    // Return the parent of x at time t
    int find(int x, int t) {
        if (t < time[x]) {
            return x;
        } else {
            return find(par[x], t);
        }
    }

    // Determine if x and y belong to the same tree at time t
    bool issame(int x, int y, int t) {
        return find(x, t) == find(y, t);
    }

    // Connect vertices x and y
    void unite(int x, int y) {
        ++now;

        x = find(x, now);
        y = find(y, now);

        if (x == y) return;

        if (rank[x] < rank[y]) swap(x, y);

        num[x].push_back(make_pair(now, size(x, now) + size(y, now)));

        par[y] = x;
        time[y] = now;
        if (rank[x] == rank[y]) ++rank[x];
    }

    // Return the number of elements in the tree containing vertex x at time t
    int size(int x, int t) {
        x = find(x, t);

        int ind = lower_bound(num[x].begin(), num[x].end(), make_pair(t, INF)) - num[x].begin();
        return num[x][ind].second;
    }
};