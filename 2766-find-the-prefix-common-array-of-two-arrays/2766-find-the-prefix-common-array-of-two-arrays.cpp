class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> st;
        int n=A.size();
        vector<int> ans(n,0);
        if(A[0]==B[0]) ans[0]=1;
        st.insert(A[0]);
        st.insert(B[0]);
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1];
            if(st.find(A[i])!=st.end()) ans[i]++;
            if(st.find(B[i])!=st.end()) ans[i]++;
            if(A[i]==B[i]) ans[i]++;
            st.insert(A[i]);
            st.insert(B[i]);
        }
        return ans;
    }
};