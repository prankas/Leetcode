class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,ans=0,odd_count=0;
        int p=0;
        while(i<n && j<n){
            if(nums[j]%2) odd_count++;
            if(odd_count==k){
                ans++;
                p++;
            }
            if(odd_count>k){
                ans++;
                while(i<n && nums[i]%2==0) i++,ans+=p;
                p=1;
                odd_count--;
                i++;
            }
            j++;
        }
        while(i<n && nums[i]%2==0) i++,ans+=p;
        return ans;
    }
};