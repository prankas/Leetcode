class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()==1) return ;
        sort(nums.begin(),nums.end());
        vector<int> ans(nums.size());
        int i=0,j=nums.size()-1;
        int p=0,f=0;
        while(p<nums.size()){
            if(!f){
                ans[p++]=nums[i++];
                f=1;
            }else{
                ans[p++]=nums[j--];
                f=0;
            }
        }
       // 4655
        int k=0,p1=1;
        for(int i=1;i<nums.size();i++){
            if(ans[i-1]==ans[i]){
              if(ans[i-2]<ans[i]) swap(ans[i],ans[k]),k+=2;
              else swap(ans[i-1],ans[k]),k+=2;
            }
        }
        nums=ans;
    }
};