class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> st;
        string sub="";
        if(s.length()<10) return {};
        vector<string> ans;
        for(int i=0;i<10;i++) sub+=s[i];
        st[sub]++;
        for(int i=10;i<s.length();i++){
            sub.erase(0,1);
            sub+=s[i];
            if(st[sub]==1) ans.push_back(sub);
            st[sub]++;
        }
        return ans;
    }
};