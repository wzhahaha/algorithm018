/**
 * func: 合并两个有序链表
 * users: wangzhen
 * time: 2020-10-22
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* newList = NULL;
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    if (l1->val < l2->val) {
        newList = l1;
        newList->next = mergeTwoLists(l1->next, l2);
    } else {
        newList = l2;
        newList->next = mergeTwoLists(l1, l2->next);
    }
    
    return newList；