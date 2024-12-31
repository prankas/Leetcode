/* Pranav Mittal*/
// give me some sunshine, give me some rain,
// give me another chance, i wanna grow up once again...

#pragma GCC optimize("O3,unroll-loops")
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
#ifdef Pranav
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
using ll = long long;
using ull = unsigned long long;
using lld = long double;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        map<int,vector<int>> mp;
        for(auto i:envelopes){
            mp[i[0]].push_back(i[1]);
        }
        int ans=1;
        for(auto &i:mp) sort(i.second.begin(),i.second.end(),greater<int>());
        for(auto i:mp[6]) cout<<i<<endl;
        map<int,int> mp1;
        for(auto i:mp){
            for(auto j:i.second){
                if(mp1.size()>0){
                auto it=mp1.lower_bound(j);
                if(it==mp1.begin()) mp1[j]=1;
                else{
                    it--;
                    mp1[j]=max(mp1[j],it->second+1);
                    it=mp1.lower_bound(j+1);
                    while(it!=mp1.end()){
                    if(it->second<=mp1[j]) mp1.erase(it->first);
                    else break;
                    it=mp1.lower_bound(j+1);
                    }
                }
                } else mp1[j]=1;
            }
        }
        ans=mp1.rbegin()->second;
        return ans;
    }
};