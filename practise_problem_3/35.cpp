#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<int> cat;
vector<vector<int>> adj;

void dfs(int u, int parent, int cnt) {
    if (cat[u])
        cnt++;
    else
        cnt = 0;

    if (cnt > m)
        return;

    bool leaf = true;

    for (int v : adj[u]) {
        if (v == parent)
            continue;
        leaf = false;
        dfs(v, u, cnt);
    }

    if (leaf)
        ans++;
}

int main() {
    cin >> n >> m;

    cat.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> cat[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    cout << ans;

    return 0;
}