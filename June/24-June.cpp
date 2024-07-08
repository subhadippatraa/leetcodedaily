#include <vector>


class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> isFlipped(n, 0);  // Auxiliary array to keep track of flips
        int flipCount = 0, flips = 0;  // Counter for total flips and current flip state

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                // Remove the effect of the flip going out of the K window
                flips ^= isFlipped[i - k];
            }

            if (nums[i] == flips) {  // If the current bit needs flipping
                if (i + k > n) return -1;  // If flipping is not possible, return -1
                flipCount++;  // Increment the flip count
                flips ^= 1;  // Toggle the flip state
                isFlipped[i] = 1;  // Mark the current position as flipped
            }
        }

        return flipCount;  // Return the total number of flips required
    }
};