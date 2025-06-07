class Solution {
public:
    bool isp(string s){
        int n=s.length()-1;
        int i=0; int j=n;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,vector<string> &v,vector<vector<string>> &ans){
        if(s==""){
            ans.push_back(v);
        }
        for(int i=0;i<s.length();i++){
            if(isp(s.substr(0,i+1)))
            {
                v.push_back(s.substr(0,i+1));
                string t=s.substr(i+1);
                solve(t,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        solve( s,v,ans);
        return ans;
    }
};