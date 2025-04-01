class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int> nxtodd(n,-1);
       int prev=-1;
       if(nums[n-1]%2) prev=n-1;
       for(int i=n-2;i>=0;i--){
        nxtodd[i]=prev;
        if(nums[i]%2) prev=i;
       }
       int ans=0;
       int i=0,j=0,cnt=0;
       for(;j<n && cnt<k;j++) if(nums[j]%2) cnt++;
       if(cnt<k) return 0;
       j--;
       while(j<n){
        int p=(nxtodd[i]-i+1);
        if(nums[i]%2) p=1;
        ans+=p;
        j++;
        if(j>=n) break;
        if(nums[j]%2){
            if(nums[i]%2) i++;
            else i=nxtodd[i]+1;
        }
       }
       return ans;
    }
};