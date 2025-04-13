class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st,ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        for(auto i:st){
            for(int j=0;j<n;j++){
                ans.insert(i^nums[j]);
            }
        }
        return ans.size();
    }
};