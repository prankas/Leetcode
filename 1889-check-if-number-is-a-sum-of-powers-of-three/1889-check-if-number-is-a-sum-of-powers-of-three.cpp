class Solution {
public:
     using ll=long long;
    bool checkPowersOfThree(int n) {
        set<int> st;
        while(n>=3){
            double p1=log(n)/log(3);
            int p=round(p1);
            if(st.find(p)!=st.end()) return 0;
            st.insert(p);
            n-=pow(3,p);
        }
        return n==0||n==1;
    }
};