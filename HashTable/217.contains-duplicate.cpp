// Time: O(n*log(n)), Space: O(log(n))
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // sort & linear search
        if (nums.empty()) return false;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; ++i) {
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // hash table
        unordered_set<int> num_set;
        for (int i: nums) {
            if (num_set.find(i) != num_set.end()) return true;
            else num_set.insert(i);
        }
        return false;
    }
};