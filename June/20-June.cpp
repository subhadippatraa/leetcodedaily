// From Chat Gpt (Have to revise it )

class Solution {
public:
    int maxDistance(std::vector<int>& position, int m) {
        // Sort the positions to prepare for binary search
        std::sort(position.begin(), position.end());

        // Initialize the binary search range
        int low = 1;
        int high = position.back() - position.front();
        int result = 0;

        // Binary search for the largest minimum distance
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceBalls(position, m, mid)) {
                result = mid;  // mid is a possible answer, try for a larger distance
                low = mid + 1;
            } else {
                high = mid - 1;  // mid is not possible, try for a smaller distance
            }
        }

        return result;
    }

private:
    // Helper function to check if we can place m balls with at least minDist distance apart
    bool canPlaceBalls(const std::vector<int>& position, int m, int minDist) {
        int count = 1;  // Place the first ball
        int lastPos = position[0];

        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minDist) {
                count++;
                lastPos = position[i];

                if (count == m) {
                    return true;
                }
            }
        }

        return false;
    }
};