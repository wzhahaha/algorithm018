/* 第一遍-递归 */
int* inorder(struct TreeNode* root, int* returnSize, int* res)
{
    if (!root) {
        return;
    }
    inorder(root->left, returnSize, res);
    res[(*returnSize)++] = root->val;
    inorder(root->right, returnSize, res);

    return res;
}

int size(struct TreeNode* root) 
{
    if (!root) {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
   int rootSize = size(root);
   int *res = (int*)malloc(sizeof(int) * rootSize);
   memset(res, 0, sizeof(int) * rootSize);
   *returnSize = 0;
   inorder(root, returnSize, res);

   return res; 
}

/* 第二遍--栈，参考网友写法 */
#define MAX_LEN 10000
#define TREE_LEN 1000
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    int *res = (int*)malloc(sizeof(int) * MAX_LEN);
    struct TreeNode** stackTree = (struct TreeNode*)malloc(sizeof(struct TreeNode*) * TREE_LEN);
    int top = 0;

    while (root || top > 0) {
        while (root) {
            stackTree[top++] = root;
            root = root->left;
        }
        root = stackTree[--top]; // 出栈，访问节点。相当于左-根-右的顺序
        res[(*returnSize)++] = root->val;
        root = root->right;
    }
    return res;
}