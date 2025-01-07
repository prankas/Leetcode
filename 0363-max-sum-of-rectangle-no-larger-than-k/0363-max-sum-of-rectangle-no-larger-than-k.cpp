class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int req) {
        int row=matrix.size(),col=matrix[0].size();
        int ans=-1e9;
        for(int i=0;i<row;i++){
           vector<int> temp(col,0);
           for(int j=i;j<row;j++){
           int prefixSum=0;
           set<int> st;
           for(int k=0;k<col;k++){
               temp[k]+=matrix[j][k];
           }
           for(int k=0;k<col;k++){
            prefixSum+=temp[k];
            if(prefixSum<=req) ans=max(ans,prefixSum);
            auto target=st.lower_bound(prefixSum-req);
            if(target!=st.end()) ans=max(ans,prefixSum-*target);
            st.insert(prefixSum);
           }
           }
        }
        return ans;
    }
};