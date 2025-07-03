#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// Leetcode problem: https://leetcode.com/problems/partition-labels/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        //create a position array
        vector<int> arr(26,0);

        for(int i = 0;i<s.size();i++)
        {
            arr[s[i] - 'a'] = i;
        }

        int end = 0;
        int i = 0;
        vector<int>res;
        while(i<s.size())
        {
            int j = i;
            end = arr[s[j] - 'a'];
            while(j<end)
            {
                end = max(end,arr[s[j] - 'a']);
                j++;
            }
            res.push_back(j-i+1);
            i = j+1;
        }
        return res;


                   

    }
};