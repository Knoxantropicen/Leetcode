// Time: O(n*log(n)), Space: O(1)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) sum += nums[i];
        return sum;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
    	// use hashmap instead of sorting
        vector<int> cnt(20001, 0);
        const int OFF = 10000;
        for (auto num: nums) ++cnt[num + OFF];	// build hashmap: (num, freq)
        int i = 0, sum = 0;
        while (i < cnt.size()) {
        	if (cnt[i] == 0) ++i;	// no appearance, pass
        	else if (cnt[i] == 1) {	// appear once, find next num and decrease freq[next] by 1
        		sum += (i - OFF);
        		while (i < cnt.size()) {
        			++i;
        			if (cnt[i] != 0) {
        				--cnt[i];
        				break;
        			}
        		}
        	}
        	else if (cnt[i] >= 2) {	// appear more then once, decrease by 2
        		cnt[i] -= 2;
        		sum += (i - OFF);
        	}
        }
        return sum;
    }
};