/*
    1. hash map
        Time complexity: O(m+n), Space complexity: O(m+n)
    2. brute force
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
        int val;
        struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
    int lengthA = 0, lengthB = 0;
    struct ListNode *current = headA;
    while (current) {
        lengthA++;
        current = current->next;
    }
    current = headB;
    while (current) {
        lengthB++;
        current = current->next;
    }
    if (lengthA > lengthB) {
        int skip = lengthA - lengthB;
        while (skip > 0) {
            headA = headA->next;
            skip--;
        }
    } else {
        int skip = lengthB - lengthA;
        while (skip > 0) {
            headB = headB->next;
            skip--;
        }
    }
    for (int i = 0; i < lengthA; i++) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

void logList(struct ListNode *head) {
    printf("List: ");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
struct ListNode *generateList(int arr[], int arrayLength) {
    if (arrayLength == 0) return NULL;
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode *current = head;
    for (int i = 1; i < arrayLength; i++) {
        current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }

    return head;
}
int main(void) {
    int arrayA[] = {4, 1, 8, 4, 5};
    int arrayB[] = {5, 6, 1, 8, 4, 5};

    int intersectVal = 8;
    // int skipA = 2;
    // int skipB = 3;

    struct ListNode *listA =
        generateList(arrayA, sizeof(arrayA) / sizeof(*arrayA));
    struct ListNode *listB =
        generateList(arrayB, sizeof(arrayB) / sizeof(*arrayB));

    logList(listA);
    logList(listB);

    struct ListNode *intersectionNode = getIntersectionNode(listA, listB);
    logList(intersectionNode);
}

/*
Given the heads of two singly linked-lists headA and headB, return the node at
which the two lists intersect. If the two linked lists have no intersection at
all, return null.

Note that the linked lists must retain their original structure after the
function returns.
*/

/*
Constraints:
    1. The number of nodes of listA is in the m.
    2. The number of nodes of listB is in the n.
    3. 1 <= m, n <= 3 * 10^4
    4. 1 <= Node.val <= 10^5
    5. 0 <= skipA < m
    6. 0 <= skipB < n
    7. intersectVal is 0 if listA and listB do not intersect.
    8. intersectVal == listA[skipA] == listB[skipB] if listA and listB
intersect.
*/