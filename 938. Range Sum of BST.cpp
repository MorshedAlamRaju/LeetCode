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

int call(TreeNode* root, int L, int R){
    if(root == NULL)return 0;
    int sum = 0;
    if(root->val <= R && root->val >= L)sum += root->val;
    sum += call(root->left, L, R);
    sum += call(root->right, L, R);
    return sum;
}


class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int range_sum = call(root, L, R);
        return  range_sum;
    }
};
