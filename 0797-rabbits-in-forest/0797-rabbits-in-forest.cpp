class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(auto i:answers) mp[i]++;
        int ans=0;
        for(auto i:mp){
            ans+=((i.second/(i.first+1))*(i.first+1));
            if((i.second%(i.first+1))>0) ans+=(i.first+1);
        }
        return ans;
    }
    
};