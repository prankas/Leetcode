class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs){
        days.push_back(500);
        sort(days.begin(),days.end());
        vector<int> dp(days.size(),0);
        int n=days.size()-1;
        for(int i=n-1;i>=0;i--){
            int a=lower_bound(days.begin(),days.end(),days[i]+1)-days.begin();
            int b=lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
            int c=lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
            dp[i]=min({costs[0]+dp[a],costs[1]+dp[b],costs[2]+dp[c]});
        }
        return dp[0];
    }
};