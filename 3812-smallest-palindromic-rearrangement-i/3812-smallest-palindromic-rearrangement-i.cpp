class Solution {
public:
    string smallestPalindrome(string s) {
         int n=s.length();
         map<char,int> mp;
         for(auto i:s) mp[i]++;
         char mid;
         for(auto i:mp){
            if(i.second % 2 ){ mid=i.first; break; }
         }
         string firsthalf="";
         for(auto i:mp){
            for(int j=1;j<=i.second/2;j++) firsthalf+=i.first;
         }
         sort(firsthalf.begin(),firsthalf.end());
         string second="";
         for(int i=firsthalf.length()-1;i>=0;i--) second+=firsthalf[i];
         if(mid>='a' && mid<='z') return firsthalf+mid+second;
         return firsthalf+second;
    }
};