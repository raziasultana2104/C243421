#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
double ans = 0.0;

void dfs(int u, int parent, double prob, int dist) {
    int children = 0;

    for (int v : adj[u]) {
        if (v != parent)
            children++;
    }

    if (children == 0) {
        ans += prob * dist;
        return;
    }

    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u, prob / children, dist + 1);
        }
    }
}

int main() {
    cin >> n;

    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 1.0, 0);

    cout << fixed << setprecision(15) << ans;

    return 0;
}