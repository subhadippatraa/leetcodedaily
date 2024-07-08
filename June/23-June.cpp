class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, right = 0, maxLength = 0;

        while (right < nums.size()) {
            while (!maxDeque.empty() && nums[right] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            while (!minDeque.empty() && nums[right] < minDeque.back()) {
                minDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);
            minDeque.push_back(nums[right]);

            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[left] == maxDeque.front()) {
                    maxDeque.pop_front();
                }
                if (nums[left] == minDeque.front()) {
                    minDeque.pop_front();
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};