#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);

        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

struct Edge {
    int u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    int maxW = 0;

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        maxW = max(maxW, edges[i].w);
    }

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) {
             return a.w < b.w;
         });

    DSU dsu(n);

    vector<vector<pair<int,int>>> tree(n + 1);

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            tree[e.u].push_back({e.v, e.w});
            tree[e.v].push_back({e.u, e.w});
        }
    }

    vector<int> parent(n + 1, -1);
    vector<int> order;
    order.reserve(n);

    stack<int> st;
    st.push(1);
    parent[1] = 0;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        order.push_back(u);

        for (auto &[v, w] : tree[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            st.push(v);
        }
    }

    vector<long long> sub(n + 1, 1);

    vector<long long> bits(maxW + n + 100, 0);

    for (int i = (int)order.size() - 1; i > 0; i--) {
        int u = order[i];

        sub[parent[u]] += sub[u];

        long long s = sub[u];
        long long pairs = s * (n - s);

        for (auto &[v, w] : tree[u]) {
            if (v == parent[u]) {
                bits[w] += pairs;
                break;
            }
        }
    }

    for (size_t i = 0; i + 1 < bits.size(); i++) {
        bits[i + 1] += bits[i] / 2;
        bits[i] %= 2;
    }

    int pos = (int)bits.size() - 1;

    while (pos > 0 && bits[pos] == 0)
        pos--;

    while (pos >= 0)
        cout << bits[pos--];

    cout << '\n';

    return 0;
}