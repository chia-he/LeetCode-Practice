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

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    // count left times from head to reverse List
    // until right times, we should make left-1 node point at right node,
    // make left node point at right+1 node.
    if (!head || !head->next) return head;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *hook = dummy;
    for (int i = 1; i < left; i++) {
        hook = hook->next;
    }
    struct ListNode *prev = hook->next;
    struct ListNode *curr = prev->next;
    struct ListNode *next;
    for (int i = left; i < right; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    hook->next->next = curr;
    hook->next = prev;
    return dummy->next;
}

int main() {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *temp = head;
    int n = 2;
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
    int left = 1;
    int right = 2;
    struct ListNode *tail = reverseBetween(head, left, right);
    printf("Reversed: ");
    while (tail) {
        printf("%d ", tail->val);
        tail = tail->next;
    }
}
/*
Given the head of a singly linked list and two integers left and right where
left <= right, reverse the nodes of the list from position left to position
right, and return the reversed list.
*/
/*
Constraints:
    1. The number of nodes in the list is n.
    2. 1 <= n <= 500
    3. -500 <= Node.val <= 500
    4. 1 <= left <= right <= n
*/