class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        int j=0;
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            if(s[i]==s[j]) lps[i]=++j;
            else{
                if(j>0) j=lps[j-1],i--;
            }
        }
        return s.substr(0,j);
    }
};