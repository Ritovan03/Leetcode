class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax(height.size());
        lmax[0] = height[0];
        vector<int> rmax(height.size());
        int i,len = height.size();
        int res = 0;
        rmax[len - 1] = height[len-1];
        for(i=1;i<len;i++)
        {
            lmax[i] = max(lmax[i-1],height[i]);
        }
        for(i=len-2;i>=0;i--)
        {
            rmax[i] = max(rmax[i+1],height[i]);
        }
        for(i=0;i<len;i++)
        {
            res+=(min(lmax[i],rmax[i]) - height[i]);
        }
        return res;
    }
};