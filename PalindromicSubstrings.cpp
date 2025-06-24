class Solution {
public:
    void helper(string s,int left,int right,int& count)
    {
        while(left>=0 && right<s.size())
        {
            
            if(s[left] != s[right])
            {
                return;
            }
            count++;
            left--;
            right++;
        }
        return;
    }
    int countSubstrings(string s) {
        int left,right,count = 0;
        //for odd length palindrome
        for(int i =0;i<s.size();i++)
        {
            helper(s,i,i,count);
        }
        //for even length palindrome
        for(int i =0;i<s.size();i++)
        {
            helper(s,i,i+1,count);
        }
        return count;
    }
};