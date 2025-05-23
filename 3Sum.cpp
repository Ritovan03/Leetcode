#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        int len = nums.size();

        // Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i) 
        {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) 
            continue;

            int left = i + 1;
            int right = len - 1;

            while (left < right) 
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) 
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Move left and right pointers to the next different numbers to avoid duplicates
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                } else if (sum < 0) 
                {
                    ++left;
                } else 
                {
                    --right;
                }
            }
        }

        return result;
    }
};