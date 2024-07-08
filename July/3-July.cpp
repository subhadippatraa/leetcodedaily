class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 5) return 0;  

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < n; ++i) {  
            maxHeap.push(nums[i]);
            if (maxHeap.size() > 4)
                maxHeap.pop();
            minHeap.push(nums[i]);
            if (minHeap.size() > 4)
                minHeap.pop();
        }

        vector<int> lar, sma; 

        while (!maxHeap.empty()) {
            sma.push_back(maxHeap.top());
            maxHeap.pop();
        }

        while (!minHeap.empty()) {
            lar.push_back(minHeap.top());
            minHeap.pop();
        }

        reverse(sma.begin(), sma.end()); 

        int mini = INT_MAX;
        for (int i = 0; i < 4; i++) {
            mini = min(mini, lar[i] - sma[i]);
        }

        return mini;
    }
};