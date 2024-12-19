class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        vector<int> b(arr.begin(),arr.end());
        sort(b.begin(),b.end());
        int j=n-1,i=n-1;
        multiset<int> st;
        while(j>=0){
            if(st.find(b[j])!=st.end()){
                st.erase(st.find(b[j]));
            } else{
                while(arr[i]!=b[j]){
                    st.insert(arr[i]);
                    i--;
                }
                i--;
            }
            j--;
            if(i==j) ans++;
        }
        return ans;
    }
};