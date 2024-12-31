class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.length();
        if(numFriends==1) return word;
        int m=n-(numFriends-1);
        string ans="";
        for(int i=0;i<n;i++){
            string p=word.substr(i,min(m,n-i));
            if(p>ans) ans=p;
        }
        return ans;
    }
};