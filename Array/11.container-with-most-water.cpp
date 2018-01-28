// Time: O(n), Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = 0, k = height.size() - 1;
        int max_area = 0;
        // j ---> <--- k (from edges to middle for higher container height and evaluate)
        while (j < k) {
            int h = min(height[j], height[k]);
            max_area = max(max_area, (k - j) * h);
            if (height[j] == h) {   // extra judgement for height[j] == height[k] == h
                while (j < k && height[j] <= h) ++j;
            } else {
                while (j < k && height[k] <= h) --k;
            }       
        }
        return max_area;
    }
};