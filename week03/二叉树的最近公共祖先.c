/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q){
    /* 二叉树为空或者结点 p/q 为根结点 */
    if (root == NULL || root == p || root == q) {
        return root;
    }

    /* 在根结点的左右子树查找 */
    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
    /* 结点 p/q 不在左子树中，就在右子树中查找，如果能找到，就返回在右子树中找到的结点（反之亦然） */
    /* 结点 p/q 分别存在左右两颗子树， 根结点为最近公共祖先 */
    /* 结点 p/q 在左右子树都找不到，则它们没有最近公共祖先 */
    return left == NULL ? right : right == NULL ? left : root;
}