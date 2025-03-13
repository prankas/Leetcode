class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int L = n + m - 1;

        vector<char> word(L);
        vector<bool> forced(L, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    int pos = i + j;
                    if (word[pos] != 0 && word[pos] != str2[j]) {
                        return "";
                    }
                    word[pos] = str2[j];
                    forced[pos] = true;
                }
            }
        }

        vector<bool> free(L, false);
        for (int i = 0; i < L; i++) {
            if (word[i] == 0) {
                word[i] = 'a';
                free[i] = true;
            }
        }

        if (n == 0) {
            return string(L, 'a');
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                if (intervalEquals(word, str2, i, m)) {
                    bool fixed = false;
                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;
                        if (free[pos]) {
                            word[pos] = 'b';
                            free[pos] = false;
                            fixed = true;
                            break;
                        }
                    }
                    if (!fixed) {
                        return "";
                    }
                }
            }
        }

        return string(word.begin(), word.end());
    }

private:
    bool intervalEquals(const vector<char>& word, const string& str2, int i, int m) {
        for (int j = 0; j < m; j++) {
            if (word[i + j] == 0 || word[i + j] != str2[j]) {
                return false;
            }
        }
        return true;
    }
};