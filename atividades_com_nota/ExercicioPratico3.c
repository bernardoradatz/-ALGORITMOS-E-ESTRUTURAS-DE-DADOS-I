/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
   if(head == NULL){
    return NULL;
   }
   if(head -> next == NULL){
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node -> val = head -> val;
    node -> left = node -> right = NULL;
    return node;
   }
   struct ListNode *slow = head;
   struct ListNode *fast = head;
   struct ListNode *prev = NULL;
   while(fast != NULL && fast -> next != NULL){
    prev = slow;
    slow = slow -> next;
    fast = fast -> next -> next;
   }
   if(prev){
    prev -> next = NULL;
   }
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
  root -> val = slow -> val;
  root -> left = sortedListToBST(head);
  root -> right = sortedListToBST(slow -> next);
  return root;
    }