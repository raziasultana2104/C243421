#include <bits/stdc++.h>
using namespace std;

int prims(int n, vector<vector<int>> edges, int start) {
    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> vis(n + 1, false);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, start});

    int mstWeight = 0;

    while (!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if (vis[node])
            continue;

        vis[node] = true;
        mstWeight += wt;

        for (auto &[next, cost] : adj[node]) {
            if (!vis[next]) {
                pq.push({cost, next});
            }
        }
    }

    return mstWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0]
            >> edges[i][1]
            >> edges[i][2];
    }

    int start;
    cin >> start;

    cout << prims(n, edges, start) << '\n';

    return 0;
}