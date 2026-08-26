class Solution {
public:
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>>&dp){
        if(ind==0){
            if(target==0 && nums[0]==0)return 2;
            if(target==0|| nums[0]==target)return 1;
            return 0;

        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int skip = solve(ind-1,target,nums,dp);
        int take =0;
        if(nums[ind]<=target){
            take = solve(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=take+skip;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int summ = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>summ || (summ+target)%2!=0)return 0;
        int sum = (summ+target)/2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,nums,dp);
    }
};