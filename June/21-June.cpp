class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n = customers.size();
        int zeroSum = 0;
        int windowSum = 0;
        int maxWindowSum = 0;

        for (int i = 0; i < n; i++) {
            if (!grumpy[i])
                zeroSum += customers[i];
            else if (i < minutes)
                windowSum += customers[i];
        }
        maxWindowSum = windowSum;
        int left = 0;
        int right = minutes;
        while (right < n) {
            if (grumpy[right] == 1)
                windowSum += customers[right];
            if (grumpy[left] == 1)
                windowSum -= customers[left];

            maxWindowSum = max(maxWindowSum, windowSum);
            right++;
            left++;
        }
        return maxWindowSum+zeroSum;
    }
};