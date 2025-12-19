/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
#include <stdbool.h>
#include <stdlib.h>

void inorderTraversal(struct TreeNode* root, int* arr, int* size) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left, arr, size);
    
    arr[(*size)] = root->val;
    (*size)++;
    
    inorderTraversal(root->right, arr, size);
}

bool findTarget(struct TreeNode* root, int k) {
    int* arr = (int*)malloc(10000 * sizeof(int));
    int size = 0;
    
    inorderTraversal(root, arr, &size);

    int left = 0;
    int right = size - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == k) {
            free(arr);
            return true;
        }
        
        if (sum < k) {
            left++;
        } else {
            right--;
        }
    }
    
    free(arr);
    return false;
}