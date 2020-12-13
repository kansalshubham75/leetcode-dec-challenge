class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int gap=2;gap<n;gap++){
            for(int l=0;l+gap<n;l++){
                int r=l+gap;
                for(int cut=l+1;cut<r;cut++){
                    dp[l][r]=max(dp[l][r],dp[l][cut]+(nums[l]*nums[cut]*nums[r])+dp[cut][r]);
                }
            }
        }
        return dp[0][n-1];
    }
};