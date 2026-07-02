class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<int> vis;

    void solve(vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;

            vis[i] = 1;
            curr.push_back(nums[i]);

            solve(nums);

            curr.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vis.assign(nums.size(), 0);
        solve(nums);
        return ans;
    }
};