class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        int i=n-1,j=m-1;
        while(i>=0 && j>=0){
            int p=str1[i]-'a',q=str2[j]-'a';
            if(p==q) j--;
            p=(p+1)%26;
            if(p==q) j--;
            i--;
        }
        if(j<0) return true;
        return false;
    }
};