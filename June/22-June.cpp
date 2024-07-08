class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n=nums.size();
        int sum=0;
        int cnt=0;
        unordered_map<int,int>mapp;
        mapp[0]=1;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i]%2;
            if(mapp.find(sum-k)!=mapp.end())
                cnt+=mapp[sum-k];
            mapp[sum]++;

        }
        return cnt;
        
    }
};