class Solution {
public:
    int char2val(char c){
        if(c=='A') return 0;
        if(c=='C') return 1;
        if(c=='G') return 2;
        if(c=='T') return 3;
        return 0;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10) return {};
        vector<string> ans;
        bitset<1<<20> s1,s2;

        int val=0;
        for(int i=0;i<10;i++){
            val = (val<<2)|char2val(s[i]);
        }
        s1.set(val);

        int mask = (1<<20)-1;
        for(int i=10;i<s.length();i++){
            val = ((val<<2) & mask)| char2val(s[i]);
            if(s2[val]) continue;
            if(s1[val]){
                ans.push_back(s.substr(i-10+1,10));
                s2.set(val);
            } else
            s1.set(val);
        }
        return ans;
    }
};