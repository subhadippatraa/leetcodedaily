class Solution {
public:
bool canMakeBouquets(const std::vector<int>& bloomDay, int m, int k, int days) {
    int bouquets = 0, flowers = 0;
    for (int bloom : bloomDay) {
        if (bloom <= days) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
                if (bouquets == m) return true;
            }
        } else {
            flowers = 0;
        }
    }
    return bouquets >= m;
}

int minDays(std::vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    long long x= long(m)*long (k);
    if (n < x) return -1;

    int low = INT_MAX, high = INT_MIN;
    for (int day : bloomDay) {
        if (day < low) low = day;
        if (day > high) high = day;
    }

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canMakeBouquets(bloomDay, m, k, mid)) high = mid;
        else low = mid + 1;
    }

    return low;
}

};