class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> row_major(n,vector<int> (m,0)),column_major(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(j==(m-1)) row_major[i][j]=(matrix[i][j]-'0');
                else{
                    row_major[i][j]+=row_major[i][j+1];
                    row_major[i][j]+=(matrix[i][j]-'0');
                    row_major[i][j]*=(matrix[i][j]-'0');
                }
            }
        }
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
              if(i==(n-1)) column_major[i][j]=(matrix[i][j]-'0');
                else{
                    column_major[i][j]+=column_major[i+1][j];
                    column_major[i][j]+=(matrix[i][j]-'0');
                    column_major[i][j]*=(matrix[i][j]-'0');
                }  
            }
        }
        vector<vector<int>> dp(n,vector<int> (m,0));
        dp[n-1][m-1]=row_major[n-1][m-1];
        int ans=dp[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==(n-1)) dp[i][j]=column_major[i][j];
                else if(j==(m-1)) dp[i][j]=row_major[i][j];
                else{
                dp[i][j]=min(row_major[i][j],column_major[i][j]);
                if(dp[i+1][j+1]>=(dp[i][j]-1)){
                     ans=max(ans,dp[i][j]*dp[i][j]);
                     continue;
                }
                else dp[i][j]=(dp[i+1][j+1]+1);
                }
                ans=max(ans,dp[i][j]*dp[i][j]);
            }
        }
       // if(ans==2) ans/=2;
        return ans;
    }
};