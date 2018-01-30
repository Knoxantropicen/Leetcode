// Time: O(10^k), Space: O(10^k*k)
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        combination(result, vector<int>(), k, n);
        return result;
    }
    void combination(vector<vector<int>>& all_sum, vector<int> prev_sum, int k, int target) {
        if (k == 0 && target == 0) {    // succeed
            all_sum.push_back(prev_sum);
            return;
        } 
        if (k < 0) return;  // fail
        for (int i = prev_sum.empty() ? 1 : prev_sum.back() + 1; i <= 9; ++i) {
            if (target < i) return; // fail
            prev_sum.push_back(i);
            combination(all_sum, prev_sum, k - 1, target - i);
            prev_sum.pop_back();
        }
    }
};