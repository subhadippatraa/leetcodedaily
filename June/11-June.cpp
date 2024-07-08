class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int, int> mapp;
        for (int i = 0; i < arr1.size(); i++)
            mapp[arr1[i]]++;

        for (int j = 0; j < arr2.size(); j++) {
            while (mapp[arr2[j]] > 0) {
                ans.push_back(arr2[j]);
                mapp[arr2[j]]--;
            }
        }

        vector<int> rem;
        for (int i = 0; i < arr1.size(); i++) {
            if (mapp[arr1[i]] > 0) {
                rem.push_back(arr1[i]);
                mapp[arr1[i]]--;
            }
        }

        sort(rem.begin(), rem.end());
        ans.insert(ans.end(), rem.begin(), rem.end());

        return ans;
    }
};