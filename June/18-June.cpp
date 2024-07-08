class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {

        int n = profit.size();
        int profitt = 0;
        vector<pair<int, int>> job;
        for (int i = 0; i < n; i++)
            job.push_back({difficulty[i], profit[i]});
        sort(job.begin(), job.end());
        sort(worker.begin(), worker.end());
        int j = 0;
        int maxp = 0;
        for (int i = 0; i < worker.size(); i++) {

            while (j < worker.size() && job[j].first <= worker[i]) {
                maxp = max(maxp, job[j].second);
                j++;
            }

            profitt += maxp;
        }
        return profitt;
    }
};
