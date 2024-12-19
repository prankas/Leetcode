class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int ans=0,mi=arr[n-1];
        if(mi==(n-1)) ans++;
        for(int i=n-2;i>=0;i--){
            mi=min(mi,arr[i]);
            if(i==mi){
                ans++;
            }
        }
        return ans;
    }
};