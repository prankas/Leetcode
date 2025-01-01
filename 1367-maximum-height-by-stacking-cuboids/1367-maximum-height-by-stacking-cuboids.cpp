class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &i:cuboids){
            sort(i.begin(),i.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int ans=0;
        vector<int> dp(cuboids.size(),0);
        for(int i=0;i<cuboids.size();i++){
            int temp=cuboids[i][2];
            for(int j=i-1;j>=0;j--){
                if(cuboids[j][2]<=cuboids[i][2] && cuboids[j][1]<=cuboids[i][1]){
                    dp[i]=max(dp[i],cuboids[i][2]+dp[j]);
                }
            }
            dp[i]=max(dp[i],temp);
        }
        return *max_element(dp.begin(),dp.end());
    }
};