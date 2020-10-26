
 
/**
 * func: 回文链表
 * users: wangzhen
 * time: 2020-10-23
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    int valNum[50001] = { 0 };
    int num = 0;
    while(head != NULL) {
        valNum[num++] = head->val;
        head = head->next;
    }

    int first;
    int end;
    for (first = 0, end = num - 1; first < end; first++, end--) {
        if (valNum[first] != valNum[end]) {
            return false;
        }
    }
    return true;
}