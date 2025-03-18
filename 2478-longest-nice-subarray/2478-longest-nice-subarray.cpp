class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> bits(32,0);
        int i=0,j=0,ans=0,n=nums.size();
        while(j<n){
           for(int k=0;k<32;k++){
            if(nums[j] & (1<<k)){
                while(bits[k]>0){
                    for(int l=0;l<32;l++){
                        if(nums[i] & (1<<l)) bits[l]--;
                    }
                    i++;
                }
                bits[k]=1;
            }
           }
           ans=max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};