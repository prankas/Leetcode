 
class Solution {
public:

// Function to compute (base^exp) % MOD using fast modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {         // If the exponent is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp /= 2;
    }
    return result;
}

// Function to precompute factorials and inverse factorials
void precomputeFactorials(vector<long long> &fact,vector<long long> &invFact) {
    int MAXi=30;
   int MOD=1e9+7;
   fact.resize(MAXi+1);
   invFact.resize(MAXi+1);
    fact[0] = 1;
    for (int i = 1; i <= MAXi; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    // Compute the inverse of factorial[MAX] using modular exponentiation
    invFact[MAXi] = modPow(fact[MAXi], MOD - 2, MOD);

    // Compute inverses for all factorials in reverse order
    for (int i = MAXi - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCk(int n, int k,vector<long long> &fact,vector<long long> &invFact) {
    int MOD=1e9+7;
    if (k > n || k < 0) return 0; // Invalid cases
    return (fact[n] * invFact[k] % MOD * invFact[n - k] % MOD) % MOD;
}

    int waysToReachStair(int k) {
      vector<long long> fact,ifact;
       precomputeFactorials(fact,ifact);
       int start=1;
       int ans=0;
       if(k==1 || k==0) ans++;
       for(int i=0;i<30;i++){
         start+=pow(2,i);
         if(start-(i+2)<=k){
            int req=start-k;
            //if(req==0) ans++;
            ans+=nCk(i+2,req,fact,ifact);
         }
       }
       return ans;
    }
};