// https://leetcode.com/problems/two-sum/description/

// Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;	// store previously found (num, indice) pairs
        vector<int> indices;
        for (int i=0; i<nums.size(); i++){
            int DemandNum = target - nums[i];
            if (hash.find(DemandNum) != hash.end()){
                indices.push_back(hash[DemandNum]);
                indices.push_back(i);
                return indices;
            }
            hash[nums[i]] = i;
        }
        return indices;
    }
};
