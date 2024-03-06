/*
    1. Iterative
        Maintain three pointers, previous, current, next.
        Time Complexity: O(n), Space Complexity: O(1)
    2. Recursive
        Time Complexity: O(n), Space Complexity: O(n)
*/
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
        int val;
        struct ListNode *next;
};
struct ListNode *reverseList_Recursive(struct ListNode *head) { 
    if(!head || !head->next) return head;
    struct ListNode *prev = NULL;
    struct ListNode *curr = reverseList_Recursive(head->next);
    head->next->next = head;
    head->next = prev;
    return curr;
}
struct ListNode *reverseList(struct ListNode *head) { 
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = head;
    while(curr){
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }    
    return prev;
}
int main() {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *temp = head;
    int n = 5;
    if (head) {
        head->val = 1;
        head->next = NULL;
        for (int i = 2; i <= n; i++) {
            temp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp = temp->next;
            temp->val = i;
            temp->next = NULL;
        }
    }
    struct ListNode *tail = reverseList_Recursive(head);
    printf("Reversed: ");
    while (tail) {
        printf("%d ", tail->val);
        tail = tail->next;
    }
}
/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
/*
Constraints:
    1. The number of nodes in the list is the range [0, 5000].
    2. -5000 <= Node.val <= 5000
*/