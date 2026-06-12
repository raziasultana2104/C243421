#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

class DSU {
private:
    vector<int> parent, rankv;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rankv.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;

        return true;
    }
};

int kruskals(int g_nodes,
             vector<int> g_from,
             vector<int> g_to,
             vector<int> g_weight) {

    vector<Edge> edges;

    int m = g_from.size();

    for (int i = 0; i < m; i++) {
        edges.push_back({g_from[i], g_to[i], g_weight[i]});
    }

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) {
             if (a.w != b.w)
                 return a.w < b.w;

             return (a.u + a.v + a.w) < (b.u + b.v + b.w);
         });

    DSU dsu(g_nodes);

    long long totalWeight = 0;
    int edgesUsed = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            totalWeight += e.w;
            edgesUsed++;

            if (edgesUsed == g_nodes - 1)
                break;
        }
    }

    return (int)totalWeight;
}

int main() {
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        cin >> g_from[i] >> g_to[i] >> g_weight[i];
    }

    cout << kruskals(g_nodes, g_from, g_to, g_weight) << '\n';

    return 0;
}
