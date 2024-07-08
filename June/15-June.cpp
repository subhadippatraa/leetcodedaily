class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> mprofit;
        for (int i = 0; i < n; i++)
            mprofit.push_back({capital[i], profits[i]});
        sort(mprofit.begin(), mprofit.end());
        priority_queue<int> maxheap;
        int i = 0;

        while (k) {
            while (i < n && mprofit[i].first <= w) {
                maxheap.push(mprofit[i].second);
                i++;
            }
            if (!maxheap.empty()) {
                w += maxheap.top();
                maxheap.pop();
            }

            k--;
        }
        return w;
    }
};