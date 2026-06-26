class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int u = cur[1];
            int stops = cur[2];

            if (u == dst)
                return cost;

            if (stops == k + 1)
                continue;

            for (auto [v, w] : adj[u]) {
                int newCost = cost + w;

                if (newCost < dist[v][stops + 1]) {
                    dist[v][stops + 1] = newCost;
                    pq.push({newCost, v, stops + 1});
                }
            }
        }

        return -1;
    }
};