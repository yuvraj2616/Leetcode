class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(j-i==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans =INT_MIN;
        for(int k =i+1;k<j;k++){
            int sol = solve(i,k,nums,dp)+solve(k,j,nums,dp)+nums[i]*nums[k]*nums[j];
            ans = max(ans, sol);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int>num;
        num.push_back(1);
        for(int i =0;i<nums.size();i++){
            num.push_back(nums[i]);

        }
        num.push_back(1);
        int m= num.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(0,m-1,num,dp);
        
    }
};