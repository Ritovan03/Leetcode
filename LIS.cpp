class Solution {
public:
    int helper(vector<int> &nums, vector<vector<int>> &dp, int curr, int prev,int n) {
        if (curr == n)
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + helper(nums, dp, curr + 1, curr,n);
        }

        int exclude = helper(nums, dp, curr + 1, prev,n);

        return dp[curr][prev + 1] = max(include, exclude);
    }

    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(nums, dp, 0, -1,n);
    }
};
