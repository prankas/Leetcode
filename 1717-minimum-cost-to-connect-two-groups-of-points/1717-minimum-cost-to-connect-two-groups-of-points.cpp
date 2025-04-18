class Solution {
public:
    int dp[13][4096]={};
    int dfs(vector<vector<int>> &cost,vector<int> &min_sz2,int i,int mask){
        if(dp[i][mask]) return dp[i][mask]-1;
        int res=i>=cost.size()?0:INT_MAX;
        if(i>=cost.size()){
            for(int j=0;j<cost[0].size();j++)
            res+=min_sz2[j]*((mask&(1<<j))==0);
        }
        else{
            for(int j=0;j<cost[0].size();j++)
            res=min(res,cost[i][j]+dfs(cost,min_sz2,i+1,mask|(1<<j)));
        }
        dp[i][mask]=res+1;
        return res;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        vector<int> min_sz2(cost[0].size(),INT_MAX);
        for(int j=0;j<min_sz2.size();j++){
            for(int i=0;i<cost.size();i++) min_sz2[j]=min(min_sz2[j],cost[i][j]);
        }
        return dfs(cost,min_sz2,0,0);
    }
};