class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
     set<int> st(banned.begin(),banned.end());
     int ans=0,sum=0;
     for(int i=1;i<=n;i++){
        if(st.find(i)!=st.end()) continue;
        sum+=i;
        if(sum<=maxSum) ans++;
        else break;
     } 
     return ans;  
    }
};