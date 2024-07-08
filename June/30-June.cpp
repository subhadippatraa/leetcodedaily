class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    
    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return false;
        if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};


//have to do it on my own later

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n), bob(n);
        int removeCount = 0;
        int aliceEdges = 0, bobEdges = 0;
        
        // Process type 3 edges first
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (alice.unite(edge[1], edge[2])) {
                    bob.unite(edge[1], edge[2]);
                    aliceEdges++;
                    bobEdges++;
                } else {
                    removeCount++;
                }
            }
        }
        
        // Process type 1 and type 2 edges
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.unite(edge[1], edge[2])) {
                    aliceEdges++;
                } else {
                    removeCount++;
                }
            } else if (edge[0] == 2) {
                if (bob.unite(edge[1], edge[2])) {
                    bobEdges++;
                } else {
                    removeCount++;
                }
            }
        }
        

        if (aliceEdges != n - 1 || bobEdges != n - 1) {
            return -1;
        }
        
        return removeCount;
    }
};