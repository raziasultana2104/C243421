class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        solve(idx + 1, nums);
        curr.pop_back();

        solve(idx + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};