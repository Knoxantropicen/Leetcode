// Time: O(n), Space: O(h_tree)
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        longest = 0;
        findLongest(root);
        return longest;
    }
    int findLongest(TreeNode* root) {
        if (!root) return 0;
        int left = findLongest(root->left), right = findLongest(root->right);
        int leftRes = 0, rightRes = 0;
        if (root->left && root->left->val == root->val) leftRes += left + 1;
        if (root->right && root->right->val == root->val) rightRes += right + 1;
        longest = max(longest, leftRes + rightRes);
        return max(leftRes, rightRes);
    }
private:
    int longest;
};