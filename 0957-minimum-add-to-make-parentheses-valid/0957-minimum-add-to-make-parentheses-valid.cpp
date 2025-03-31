class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        int count=0,ans=0;
        for(auto i:s){
            if(i=='(') count++;
            else{
                if(count) count--;
                else ans++;
            }
        }
        return ans+count;
    }
};