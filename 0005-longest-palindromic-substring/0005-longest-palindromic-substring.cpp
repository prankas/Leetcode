class Solution {
public:
    bool isPalindrome(string &s){
        string p=s;
        reverse(p.begin(),p.end());
        if(p==s) return true;
        return false;
    }

    int chk(int mid,string &s){
        int n=s.length();
        for(int L=0;L+mid<=n;L++){
            string p=s.substr(L,mid);
            if(isPalindrome(p)) return L;
        }
        return -1;
    }

    string longestPalindrome(string s) {
        int n=s.length();
        int best_len=0;
        string best_s="";
        for(int parity:{0,1}){
            int low=1,high=n;
            if(low%2 != parity) low++;
            if(high%2 != parity) high--;
            while(low<=high){
                int mid=(low+high)/2;
                if(mid%2 != parity) mid++;
                if(mid>high) break;
                int tmp=chk(mid,s);
                if(tmp != -1){
                    if(best_len<mid){
                    best_len=mid;
                    best_s=s.substr(tmp,mid);
                    }
                    low=mid+2;
                } else high=mid-2;
            }
        }
        return best_s;
    }
};