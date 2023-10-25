/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return vector<int>();
        vector<int> ret;
        int cur_layer = 1;
        int layer_max = INT_MIN;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        while (q.size() > 0){
            auto& p = q.front();
            int layer = p.second;
            TreeNode* node = p.first;
            if (layer > cur_layer){
                ret.push_back(layer_max);
                cur_layer = layer;
                layer_max = INT_MIN;
            }
            layer_max = max(layer_max, node->val);
            if (node->left != nullptr){
                q.push(make_pair(node->left, cur_layer + 1));
            }
            if (node->right != nullptr){
                q.push(make_pair(node->right, cur_layer + 1));
            }
            q.pop();
        }
        ret.push_back(layer_max);
        return ret;
    }
};
