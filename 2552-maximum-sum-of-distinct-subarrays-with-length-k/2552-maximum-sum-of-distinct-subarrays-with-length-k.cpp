class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0,ans=0;
        map<int,int> st;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            st[nums[i]]++;
        }
        if(st.size()==k) ans=sum;
        for(int i=k;i<n;i++){
            st[nums[i-k]]--;
            sum-=nums[i-k];
            if(st[nums[i-k]]==0) st.erase(nums[i-k]);
            st[nums[i]]++;
            sum+=nums[i];
            if(st.size()==k) ans=max(ans,sum);
        }
        return ans;
    }
};