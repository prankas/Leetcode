class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        int temp=1;
        arr.push_back(1e5);
        int m=0,n=arr.size();
        int i=0;
        while(i<n){
         int temp=1,m=0;
         i++;
         while(i<n && arr[i]>arr[i-1]){
            temp++;
            i++;
         }
         if(i>=n) break;
         if(temp==1) continue;
         if(arr[i]==arr[i-1]){
            continue;
         }
         while(i<n && arr[i]<arr[i-1]) temp++,i++;
         ans=max(ans,temp);
         i--;
        }
        return ans;
    }
};