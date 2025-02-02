// A simple segment tree for range minimum queries.
struct SegTree {
    int size;
    vector<int> tree;
    const int INF = 1e9;
 
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, INF);
    }
 
    // point update: set tree[pos] = min(tree[pos], val)
    void update(int pos, int val) {
        pos += size;
        tree[pos] = min(tree[pos], val);
        for (pos /= 2; pos >= 1; pos /= 2)
            tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
    }
 
    // query minimum in range [l, r]
    int query(int l, int r) {
        int res = INF;
        l += size; r += size;
        while (l <= r) {
            if (l % 2 == 1) { res = min(res, tree[l]); l++; }
            if (r % 2 == 0) { res = min(res, tree[r]); r--; }
            l /= 2; r /= 2;
        }
        return res;
    }
};
 
class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;
        bool foundAny = false;
 
        // Precompute prefix sums for each digit 0-4.
        vector<vector<int>> prefix(5, vector<int>(n + 1, 0));
        for (int d = 0; d < 5; d++) {
            for (int i = 0; i < n; i++) {
                prefix[d][i + 1] = prefix[d][i] + ((s[i] - '0') == d);
            }
        }
 
        // For each ordered pair (a,b) with a != b.
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                if (a == b) continue;
 
                // Build arrays for our prefix difference and parity info.
                // For indices 0..n, where index i represents prefix[0..i-1]
                vector<int> diff(n + 1, 0); // diff[i] = prefix[a][i] - prefix[b][i]
                vector<int> pa(n + 1, 0), pb(n + 1, 0); // parity for digit a and b counts
                vector<int> cntB(n + 1, 0); // actual count for digit b at prefix index
                for (int i = 0; i <= n; i++) {
                    diff[i] = prefix[a][i] - prefix[b][i];
                    pa[i] = prefix[a][i] & 1;
                    pb[i] = prefix[b][i] & 1;
                    cntB[i] = prefix[b][i];
                }
 
                // We will answer queries for valid i (prefix indices) for substrings ending at j-1,
                // i.e. with j (ranging from k to n) such that substring s[i .. j-1] has length >= k.
                // We need to select i in [0, j - k] that satisfy:
                //    pa[i] != pa[j]    and   pb[i] == pb[j]
                // and we require cntB[i] <= cntB[j] - 1 (so that frequency of b in substring is >0).
                // The candidate value from such an i is diff[j] - diff[i].
                // We maintain (for each state) a segment tree keyed by cntB[i] (range 0..n)
                // that stores the minimum diff[i] for indices i added so far.
                const int KEY_RANGE = n + 1;
                const int INF = 1e9;
                // Create 2 x 2 segment trees (for each combination of (pa, pb)).
                vector<vector<SegTree>> seg(2, vector<SegTree>(2, SegTree(KEY_RANGE)));
                // (We reinitialize them below for each pair (a,b).)
 
                // p will be the pointer to indices that are now "eligible" (i.e. i <= j - k).
                int p = 0;
                // Iterate over j from 0 to n (j is the prefix index for the substring ending at j-1)
                for (int j = 0; j <= n; j++) {
                    // Before processing j, add all indices i such that i <= j - k.
                    while (p <= j - k) {
                        int key = cntB[p];  // key in [0, n]
                        int val = diff[p];
                        int paVal = pa[p], pbVal = pb[p];
                        seg[paVal][pbVal].update(key, val);
                        p++;
                    }
                    if (j >= k) {
                        // For substring ending at j-1, we need to choose i with:
                        // pa[i] != pa[j] and pb[i] == pb[j].
                        int req_pa = 1 - pa[j]; // opposite parity of pa[j]
                        int req_pb = pb[j];
                        // Also require cntB[i] <= cntB[j] - 1, so key up to cntB[j]-1.
                        int maxKey = cntB[j] - 1;
                        if (maxKey >= 0) {
                            int best = seg[req_pa][req_pb].query(0, maxKey);
                            if (best < INF) {
                                int candidate = diff[j] - best;
                                ans = max(ans, candidate);
                                foundAny = true;
                            }
                        }
                    }
                }
            }
        }
 
        return foundAny ? ans : -1;
    }
};
 