class Solution {
public:
    int longestValidParentheses(string s) {
      int n=s.length();
      if(n==0) return 0;
      vector<int> dp(n,0);
      for(int i=1;i<n;i++){
        if(s[i]=='(') continue;
        else{
            if(s[i-1]=='(') dp[i]=2+(((i-2)>=0)?dp[i-2]:0);
            else if(dp[i-1]==0) continue;
            else{
                int pos=(i-1)-dp[i-1];
                if(pos<0 || s[pos]!='(') continue;
                else dp[i]=dp[i-1]+2+(((pos-1)>=0)?dp[pos-1]:0);
            }
        }
      }
      return *max_element(dp.begin(),dp.end());
    }
};