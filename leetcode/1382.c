/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void inorder(struct TreeNode* root, struct TreeNode** nodes, int* size) {
    if (!root) return;
    inorder(root->left, nodes, size);
    nodes[(*size)++] = root;
    inorder(root->right, nodes, size);
}

struct TreeNode* build(struct TreeNode** nodes, int start, int end) {
    if (start > end) return NULL;
    
    int mid = start + (end - start) / 2;
    struct TreeNode* root = nodes[mid];
    
    root->left = build(nodes, start, mid - 1);
    root->right = build(nodes, mid + 1, end);
    
    return root;
}
struct TreeNode* balanceBST(struct TreeNode* root) {
    struct TreeNode* nodes[10001]; 
    int size = 0;
    
    inorder(root, nodes, &size);
    return build(nodes, 0, size - 1);
}