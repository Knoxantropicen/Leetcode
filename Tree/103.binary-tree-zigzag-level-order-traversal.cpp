// Time: O(n), Space: O(tree_w)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> list;
        list.push(root);
        bool ordered = true;
        while (!list.empty()) {
            int size = list.size();
            vector<int> level_res(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = list.front();
                list.pop();
                int index = ordered ? i : size - i - 1;
                level_res[index] = node->val;
                if (node->left) list.push(node->left);
                if (node->right) list.push(node->right);
            }
            result.push_back(level_res);
            ordered = !ordered;
        }
        return result;
    }
};