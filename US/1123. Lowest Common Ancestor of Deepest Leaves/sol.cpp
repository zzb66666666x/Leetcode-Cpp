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
private:
    TreeNode* commonNode;
    int commonNodeDepth;
    int maxDepth;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        commonNode = root;
        commonNodeDepth = 0;
        maxDepth = 0;
        dfs(root, 0);
        return commonNode;
    }

    int dfs(TreeNode* node, int depth){
        if (node->left == nullptr && node->right == nullptr){
            if (depth > maxDepth){
                maxDepth = depth;
                commonNode = node;
                commonNodeDepth = depth;
            }
            return depth;
        }
        int left_depth = -1;
        int right_depth = -1;
        if (node->left != nullptr){
            left_depth = dfs(node->left, depth+1);
        }
        if (node->right != nullptr){
            right_depth = dfs(node->right, depth+1);
        }
        int maxval = max(left_depth, right_depth);
        if (left_depth == right_depth && maxval == maxDepth){
            commonNode = node;
            commonNodeDepth = depth;
        }
        return maxval;
    }
};
