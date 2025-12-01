/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* ListaReversa(struct ListNode* head){
    struct ListNode *ant = NULL;
    struct ListNode *next = NULL;
    
    while(head != NULL){
        next = head -> next;
        head -> next = ant;
        ant = head;
        head = next;
    }
    
    return ant;
}

void reorderList(struct ListNode* head) {
    if(!head || !head->next){
        return;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast -> next && fast -> next -> next){
        slow = slow -> next;
        fast = fast -> next-> next;
    }

    struct ListNode *list2 = ListaReversa(slow->next);
    slow -> next = NULL;

    struct ListNode *list1 = head;
    struct ListNode *temp1, *temp2;

    while(list2){
        temp1 = list1 -> next;
        temp2 = list2 -> next;

        list1 -> next = list2;
        list2 -> next = temp1;

        list1 = temp1;
        list2 = temp2;  
    } 
}