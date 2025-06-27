#include <vector>
using namespace std;
class Solution {
public:
    bool helper(vector<int>& nums,int target,int ind,vector<vector<int>>& dp)
    {
        if(target == 0)
        {
            return true;
        }
        if(ind == nums.size() && target!=0)
        {
            return false;
        }
        if(dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        bool take = false;
        if(nums[ind]<=target)
        {
            take = helper(nums,target-nums[ind],ind+1,dp);
        }
        bool skip = helper(nums,target,ind+1,dp);
        return dp[ind][target] = (take | skip);
    }
    bool canPartition(vector<int>& nums) {
        
        //check if sum is even
        int sum = 0;
        for(int num:nums)
        {
            sum+=(int) num;
        }
        if(sum%2 == 1)
        {
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return helper(nums,target,0,dp);
    }
};