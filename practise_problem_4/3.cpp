class Solution {
public:
    vector<string> ans;

    void solve(int idx, string &s) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }

        if (isdigit(s[idx])) {
            solve(idx + 1, s);
        } else {
            s[idx] = tolower(s[idx]);
            solve(idx + 1, s);

            s[idx] = toupper(s[idx]);
            solve(idx + 1, s);
        }
    }

    vector<string> letterCasePermutation(string s) {
        solve(0, s);
        return ans;
    }
};