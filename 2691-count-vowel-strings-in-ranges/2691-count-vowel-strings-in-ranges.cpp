class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<char> vowel={'a','e','i','o','u'};
        set<char> vowels(vowel.begin(),vowel.end());
        vector<int> prefix(words.size(),0);
        for(int i=0;i<words.size();i++){
            if(vowels.find(words[i][0])!=vowels.end() && vowels.find(words[i][words[i].length()-1])!=vowels.end())  prefix[i]=1;
        }
        for(int i=1;i<words.size();i++) prefix[i]+=prefix[i-1];
        vector<int> ans;
        for(auto i:queries){
            if(i[0]==0) ans.push_back(prefix[i[1]]);
            else ans.push_back(prefix[i[1]]-prefix[i[0]-1]);
        }
        return ans;
    }
};