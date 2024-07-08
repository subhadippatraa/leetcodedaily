class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<set<int>> ancestors(n);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : adj[node]) {
                ancestors[child].insert(node);
                ancestors[child].insert(ancestors[node].begin(), ancestors[node].end());
                if (--inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};