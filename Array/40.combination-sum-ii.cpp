// Time: O(n^n), Space: O(n^(n+1))
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return vector<vector<int>>();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        combination(result, vector<int>(), candidates, 0, target);
        return result;
    }
    void combination(vector<vector<int>>& all_sum, vector<int> prev_sum, vector<int>& candidates, int pos, int target) {
        if (target == 0) {  // succeed
            all_sum.push_back(prev_sum);
            return;
        }
        for (int i = pos; i < candidates.size(); ++i) {
            if (target < candidates[i]) return; // fail
            if (i > pos && candidates[i] == candidates[i - 1]) continue;    // remove duplicate
            prev_sum.push_back(candidates[i]);
            combination(all_sum, prev_sum, candidates, i + 1, target - candidates[i]);
            prev_sum.pop_back();
        }
    }
};