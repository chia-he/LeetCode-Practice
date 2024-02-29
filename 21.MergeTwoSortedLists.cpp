/*
    1. Iterative
        Maintain tow pointers, one for head and one for tail.
        Time: O(n+m), Space: O(1)
        n is the length of list1, m is the length of list2.
    2. Recursive
        Time: O(n+m), Space: O(n+m)
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr) return list2;
            if (list2 == nullptr) return list1;
            ListNode* head = new ListNode();
            ListNode* current = head;
            while (list1 && list2) {
                if (list1->val < list2->val) {
                    current->next = list1;
                    list1 = list1->next;
                } else {
                    current->next = list2;
                    list2 = list2->next;
                }
                current = current->next;
            }
            if (list1 != nullptr) current->next = list1;
            if (list2 != nullptr) current->next = list2;
            return head->next;
        }
        ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr) return list2;
            if (list2 == nullptr) return list1;
            if (list1->val < list2->val) {
                list1->next = mergeTwoListsRecursive(list1->next, list2);
                return list1;
            } else {
                list2->next = mergeTwoListsRecursive(list1, list2->next);
                return list2;
            }
        }
};
int main() {
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    Solution solution;
    ListNode* ans = solution.mergeTwoLists(list1, list2);
    // cout << "Output: " << ans<< endl;
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}

/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists. Return the head of the merged linked
list.
*/
/*
Constraints:
    1.  The number of nodes in both lists is in the range [0, 50].
    2.  -100 <= Node.val <= 100
    3.  Both list1 and list2 are sorted in non-decreasing order.
*/