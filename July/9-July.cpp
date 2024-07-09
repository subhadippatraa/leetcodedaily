class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWaitingTime = 0;
        int currentTime = 0;
        
        for (const auto& customer : customers) {
            int arrivalTime = customer[0];
            int prepTime = customer[1];
            
            currentTime = max(currentTime, arrivalTime);
            int waitingTime = (currentTime + prepTime) - arrivalTime;
            totalWaitingTime += waitingTime;
            currentTime += prepTime;
        }
        
        return static_cast<double>(totalWaitingTime) / customers.size();
    }
};
