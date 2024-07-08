class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        
        for (const auto& edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        sort(degree.begin(), degree.end());
        
        long long importance = 0;
        for (int i = 0; i < n; ++i) {
            importance += (long long)degree[i] * (i + 1);
        }
        
        return importance;
    }
};